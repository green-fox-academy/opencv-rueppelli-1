//
// Created by Gé on 2019. 01. 30..
//

#include "crud.h"

sqlite3 *myDataBase;
char *zErrMsg = 0;
int rc;
char *sql;
char buffer[100];

static int callBack(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int readDataBase(const char *databasePath) //If doesn't exist, creates one.
{
    rc = sqlite3_open(databasePath, &myDataBase);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(myDataBase));
        return (0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    return 0;
}

int createRecord(std::string databasePath, std::string path)
{
    cv::Mat img = cv::imread(path);

    if (img.empty())
    {
        printf("Error opening image: %s\n", path.c_str());
        return 1;
    }

    unsigned long long int x = databasePath.length();
    char char_database_path[x + 1];
    strcpy(char_database_path, databasePath.c_str());

    unsigned long long int y = path.length();
    char char_path[y + 1];
    strcpy(char_path, path.c_str());

    rc = sqlite3_open(char_database_path, &myDataBase);

    sprintf(buffer, R"(INSERT INTO Pictures VALUES("%s", DATETIME(), "%d", "%d");)", char_path, img.cols, img.rows);

    rc = sqlite3_exec(myDataBase, buffer, callBack, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 1;
    } else {
        fprintf(stdout, "Records created successfully\n");
        return 0;
    }
}

int deleteRecord(std::string databasePath, std::string userCmdAfterWhere)
{
    unsigned long long int x = databasePath.length();
    char char_database_path[x + 1];
    strcpy(char_database_path, databasePath.c_str());

    unsigned long long int y = userCmdAfterWhere.length();
    char char_user_cmd[y + 1];
    strcpy(char_user_cmd, userCmdAfterWhere.c_str());

    rc = sqlite3_open(char_database_path, &myDataBase);

    sprintf(buffer, "DELETE FROM Pictures WHERE %s;", char_user_cmd);

    rc = sqlite3_exec(myDataBase, buffer, callBack, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 1;
    } else {
        fprintf(stdout, "Record(s) deleted successfully\n");
        return 0;
    }

}

int updateRecord(std::string databasePath, std::string userCmdAfterSet)
{
    unsigned long long int x = databasePath.length();
    char char_database_path[x + 1];
    strcpy(char_database_path, databasePath.c_str());

    unsigned long long int y = userCmdAfterSet.length();
    char char_user_cmd[y + 1];
    strcpy(char_user_cmd, userCmdAfterSet.c_str());

    rc = sqlite3_open(char_database_path, &myDataBase);

    sprintf(buffer, "UPDATE Pictures SET %s;", char_user_cmd);

    rc = sqlite3_exec(myDataBase, buffer, callBack, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 1;
    } else {
        fprintf(stdout, "Record(s) updated successfully\n");
        return 0;
    }
}

int selectRecords(std::string databasePath, std::string chooseRecord)
{

    unsigned long long int x = databasePath.length();
    char char_database_path[x + 1];
    strcpy(char_database_path, databasePath.c_str());

    unsigned long long int y = chooseRecord.length();
    char char_choose_record[x + 1];
    strcpy(char_choose_record, chooseRecord.c_str());

    sprintf(buffer, "SELECT %s FROM Pictures;", char_choose_record);

    rc = sqlite3_exec(myDataBase, buffer, callBack, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 1;
    } else {
        fprintf(stdout, "Record(s) selected successfully\n");
        return 0;
    }
}
