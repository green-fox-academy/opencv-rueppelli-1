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

int readDataBase(std::string databasePath)
{
    unsigned long long int x = databasePath.length();
    char charDatabasePath[x + 1];
    strcpy(charDatabasePath, databasePath.c_str());

    rc = sqlite3_open(charDatabasePath, &myDataBase);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(myDataBase));
        return (0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    return 0;
}

int createRecord(std::string databasePath, std::string tableName, std::string path, int detectedCircles)
{
    cv::Mat img = cv::imread(path);

    if (img.empty())
    {
        printf("Error opening image: %s\n", path.c_str());
        return 1;
    }

    unsigned long long int x = databasePath.length();
    char charDatabasePath[x + 1];
    strcpy(charDatabasePath, databasePath.c_str());

    unsigned long long int y = path.length();
    char charPath[y + 1];
    strcpy(charPath, path.c_str());

    unsigned long long int z = tableName.length();
    char charTableName[z + 1];
    strcpy(charTableName, tableName.c_str());

    rc = sqlite3_open(charDatabasePath, &myDataBase);

    int lol = 3;
    int lol2 = 4;
    sprintf(buffer, "INSERT INTO %s(path, processingTime, detectedCircles) VALUES(\"%s\", %d, %d);", charTableName, charPath, lol, detectedCircles);

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

int deleteRecord(std::string databasePath, std::string tableName, std::string userCmdAfterWhere)
{
    unsigned long long int x = databasePath.length();
    char charDatabasePath[x + 1];
    strcpy(charDatabasePath, databasePath.c_str());

    unsigned long long int z = tableName.length();
    char charTableName[z + 1];
    strcpy(charTableName, tableName.c_str());

    unsigned long long int y = userCmdAfterWhere.length();
    char charUserCmd[y + 1];
    strcpy(charUserCmd, userCmdAfterWhere.c_str());

    rc = sqlite3_open(charDatabasePath, &myDataBase);

    sprintf(buffer, "DELETE FROM %s WHERE %s;", charTableName, charUserCmd);

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

int updateRecord(std::string databasePath, std::string tableName, std::string userCmdAfterSet)
{
    unsigned long long int x = databasePath.length();
    char charDatabasePath[x + 1];
    strcpy(charDatabasePath, databasePath.c_str());

    unsigned long long int z = tableName.length();
    char charTableName[z + 1];
    strcpy(charTableName, tableName.c_str());

    unsigned long long int y = userCmdAfterSet.length();
    char charUserCmd[y + 1];
    strcpy(charUserCmd, userCmdAfterSet.c_str());

    rc = sqlite3_open(charDatabasePath, &myDataBase);

    sprintf(buffer, "UPDATE %s SET %s;", charTableName, charUserCmd);

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

int selectRecords(std::string databasePath, std::string tableName, std::string chooseRecord)
{

    unsigned long long int x = databasePath.length();
    char charDatabasePath[x + 1];
    strcpy(charDatabasePath, databasePath.c_str());

    unsigned long long int z = tableName.length();
    char charTableName[z + 1];
    strcpy(charTableName, tableName.c_str());

    unsigned long long int y = chooseRecord.length();
    char charChooseRecord[y + 1];
    strcpy(charChooseRecord, chooseRecord.c_str());

    rc = sqlite3_open(charDatabasePath, &myDataBase);

    sprintf(buffer, "SELECT %s FROM %s;", charChooseRecord, charTableName);

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
