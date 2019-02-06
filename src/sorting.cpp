//
// Created by EXEC_NOIR on 2/4/2019.
//

#include "sorting.h"


std::vector<int> quickSort(std::vector<int> unsorted, int low, int high, int &counter, int order)
{
    std::vector<int> sorted = unsorted;
    sortVector(sorted, low, high, counter, order);
    return sorted;
}

int* quickSort(int* array, int low, int high, int &counter, int order)
{
    int* sorted = array;
    sortArray(sorted, low, high, counter, order);
    return sorted;
}

void sortVector(std::vector<int> &unsorted, int low, int high, int &counter, int order)
{
    if(order == 1) {
        int i = low;
        int j = high;
        int middle = i + (j - i) / 2;
        int p = unsorted[middle];

        while (i <= j) {
            while (unsorted[i] < p) {
                i++;
            }
            while (unsorted[j] > p) {
                j--;
            }
            if (i <= j) {
                std::swap(unsorted[i], unsorted[j]);
                counter++;
                i++;
                j--;
            }
        }
        if (i < high) {
            sortVector(unsorted, i, high, counter, 1);
        }
        if (j > low) {
            sortVector(unsorted, low, j, counter, 1);
        }
    }else if(order == 0){
        int i = low;
        int j = high;
        int middle = (i + j) / 2;
        int p = unsorted[middle];

        while (i <= j) {
            while (unsorted[i] > p) {
                i++;
            }
            while (unsorted[j] < p) {
                j--;
            }
            if (i <= j) {
                std::swap(unsorted[i], unsorted[j]);
                counter++;
                i++;
                j--;
            }
        }
        if (j > low) {
             sortVector(unsorted, low, j, counter, 0);
        }
        if (i < high) {
             sortVector(unsorted, i, high, counter, 0);
        }
    }
}

void sortArray(int* array, int low, int high, int &counter, int order)
{
    if (order == 1) {
        int i = low;
        int j = high;
        int middle = (i + j) / 2;
        int p = array[middle];
        int temp;

        while (i <= j) {
            while (array[i] < p) {
                i++;
            }
            while (array[j] > p) {
                j--;
            }
            if (i <= j) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                counter++;
                i++;
                j--;
            }

        }
        if (j > low) {
            sortArray(array, low, j, counter, order);
        }
        if (i < high) {
            sortArray(array, i, high, counter, order);
        }
    } else if (order == 0) {
        int i = low;
        int j = high;
        int middle = (i + j) / 2;
        int p = array[middle];
        int temp;

        while (i <= j) {
            while (array[i] > p) {
                i++;
            }
            while (array[j] < p) {
                j--;
            }
            if (i <= j) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                counter++;
                i++;
                j--;
            }

        }
        if (j > low) {
            sortArray(array, low, j, counter, order);
        }
        if (i < high) {
            sortArray(array, i, high, counter, order);
        }
    }else{
        return sortArray(array, low, high, counter, 1);
    }
}

