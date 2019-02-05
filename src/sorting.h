#ifndef OPENCV_RUEPELLI_1_SORTING_H
#define OPENCV_RUEPELLI_1_SORTING_H

#include <vector>
#include <opencv2/core/utility.hpp>
#include <iostream>

int* insertion_sort(int *array, int size, int command = 1);
std::vector<int> insertion_sort(std::vector<int>& vector, int size, int command = 1);

#endif //OPENCV_RUEPELLI_1_SORTING_H
