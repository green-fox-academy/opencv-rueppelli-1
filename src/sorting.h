#ifndef OPENCV_RUEPELLI_1_SORTING_H
#define OPENCV_RUEPELLI_1_SORTING_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <opencv2/core/utility.hpp>

int* insertionSort(int *array, int size, int &counter, int command = 1);
std::vector<int> insertionSort(std::vector<int> vector, int size, int &counter, int command = 1);

void sortVector(std::vector<int> &unsorted, int low, int high, int &counter, int order = 1);
void sortArray(int* array, int low, int high, int &counter, int order = 1);
std::vector<int> quickSort(std::vector<int> unsorted, int low, int high, int &counter, int order = 1);
int* quickSort(int* array, int low, int high, int &counter, int order = 1);

std::vector<int> selectionSort(std::vector<int> myVector, int &counter, int order = 1);
int* selectionSort(int array[], int sizeOfArray, int &counter, int order = 1);

void merge(int* array, int low, int middle, int high, int &counter, int order);
void mergeSortInit(int* array, int low, int high, int &counter, int order = 1);
void merge(std::vector<int> &vector, int low, int middle, int high, int &counter, int order);
void mergeSortInit(std::vector<int> &vector, int low, int high, int &counter, int order = 1);
std::vector<int> mergeSort(std::vector<int> unsorted, int low, int high, int &counter, int order);
int* mergeSort(int *unsorted, int low, int high, int &counter, int order);

int* shellSort(int* array, int size, int &counter, int command);
std::vector<int> shellSort(std::vector<int> &vector, int size, int &counter, int command);


#endif //OPENCV_RUEPELLI_1_SORTING_H
