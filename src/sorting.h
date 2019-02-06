#ifndef OPENCV_RUEPELLI_1_SORTING_H
#define OPENCV_RUEPELLI_1_SORTING_H
#include <vector>
#include <iostream>
#include <chrono>

std::vector<int> selectionSort(std::vector<int> myVector, int &counter, int order = 1);
int* selectionSort(int array[], int sizeOfArray, int &counter, int order = 1);

#endif //OPENCV_RUEPELLI_1_SORTING_H
