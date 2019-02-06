//
// Created by EXEC_NOIR on 2/4/2019.
//
#ifndef OPENCV_RUEPELLI_1_SORTING_H
#define OPENCV_RUEPELLI_1_SORTING_H

#include <iostream>
#include <vector>
#include <algorithm>


void sortVector(std::vector<int> &unsorted, int low, int high, int &counter, int order = 1);
void sortArray(int* array, int low, int high, int &counter, int order = 1);
std::vector<int> quickSort(std::vector<int> unsorted, int low, int high, int &counter, int order = 1);
int* quickSort(int* array, int low, int high, int &counter, int order = 1);



#endif //OPENCV_RUEPELLI_1_SORTING_H
