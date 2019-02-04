#ifndef OPENCV_RUEPELLI_1_CRUD_H
#define OPENCV_RUEPELLI_1_CRUD_H

#include <sqlite3/sqlite3.h>
#include <iostream>
#include <cstring>
#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>

static int callBack(void *NotUsed, int argc, char **argv, char **azColName);
int readDataBase(std::string databasePath);
int createRecord(std::string databasePath, std::string tableName, std::string path, double processingTime, int detectedCircles);
int deleteRecord(std::string databasePath, std::string tableName, int id);
int updateRecord(std::string databasePath, std::string tableName, std::string userCmdAfterSet);
int selectRecords(std::string databasePath, std::string tableName, std::string chooseRecord);

#endif //OPENCV_RUEPELLI_1_CRUD_H
