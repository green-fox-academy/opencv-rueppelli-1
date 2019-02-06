#ifndef OPENCV_RUEPELLI_1_SORTING_H
#define OPENCV_RUEPELLI_1_SORTING_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <opencv2/core/utility.hpp>

int* insertion_sort(int *array, int size, int &counter, int command = 1);
std::vector<int> insertion_sort(std::vector<int>& vector, int size, int &counter, int command = 1);

void sortVector(std::vector<int> &unsorted, int low, int high, int &counter, int order = 1);
void sortArray(int* array, int low, int high, int &counter, int order = 1);
std::vector<int> quickSort(std::vector<int> unsorted, int low, int high, int &counter, int order = 1);
int* quickSort(int* array, int low, int high, int &counter, int order = 1);

std::vector<int> selectionSort(std::vector<int> myVector, int &counter, int order = 1);
int* selectionSort(int array[], int sizeOfArray, int &counter, int order = 1);

#endif //OPENCV_RUEPELLI_1_SORTING_H
