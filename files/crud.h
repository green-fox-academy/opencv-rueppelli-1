//
// Created by Gé on 2019. 01. 30..
//

#ifndef OPENCV_RUEPELLI_1_CRUD_H
#define OPENCV_RUEPELLI_1_CRUD_H

#include <sqlite3/sqlite3.h>
#include <iostream>
#include <cstring>
#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>

static int callBack(void *NotUsed, int argc, char **argv, char **azColName);
int readDataBase(const char* databasePath);
int createRecord(std::string databasePath, std::string path);
int deleteRecord(std::string databasePath, std::string userCmdAfterWhere);
int updateRecord(std::string databasePath, std::string userCmdAfterSet);
int selectRecords(std::string databasePath, std::string chooseRecord);

#endif //OPENCV_RUEPELLI_1_CRUD_H
