#include "sorting.h"

std::vector<int> selectionSort(std::vector<int> myVector, int &counter, int order)
{
    for (int i = 0; i < myVector.size(); ++i) {
        for (int j = i + 1; j < myVector.size(); ++j) {
            if(order == 1) {
                if(myVector[i] > myVector [j]){
                    std::swap(myVector[i], myVector[j]);
                    counter ++;
                }
            }else{
                if(myVector[i] < myVector [j]) {
                    std::swap(myVector[i], myVector[j]);
                    counter++;
                }
            }
        }
    }
   return myVector;
}

int* selectionSort(int myArray[], int sizeOfArray, int &counter, int order)
{
    for (int i = 0; i < sizeOfArray; ++i) {
        for (int j = i + 1; j < sizeOfArray; ++j) {
            if(order == 1) {
                if(myArray[i] > myArray [j]){
                    std::swap(myArray[i], myArray[j]);
                    counter ++;
                }
            }else{
                if(myArray[i] < myArray [j]) {
                    std::swap(myArray[i], myArray[j]);
                    counter++;
                }
            }
        }
    }
    return myArray;
}

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

int *insertion_sort(int *array, int size, int command)
{
    auto start = cv::getTickCount();
    int counter = 0;
    if (command == 1) {
        for (int i = 1; i < size; i++) {
            int temp_var = array[i];
            int j = i - 1;

            while (array[j] > temp_var && j >= 0) {
                array[j + 1] = array[j];
                j--;
                counter++;
            }
            array[j + 1] = temp_var;
        }
    } else if (command == 0) {
        for (int i = 1; i < size; i++) {
            int temp_var = array[i];
            int j = i - 1;

            while (array[j] < temp_var && j >= 0) {
                array[j + 1] = array[j];
                j--;
                counter++;
            }
            array[j + 1] = temp_var;
        }
    }

    auto finish = cv::getTickCount();
    double duration = (finish - start) / cv::getTickFrequency();
    std::cout << "Time taken by function: " << duration << " microseconds" << std::endl;

    std::cout << "It was " << counter << " steps to the result." << std::endl;
    return array;
}

std::vector<int> insertion_sort(std::vector<int> &vector, int size, int command)
{
    auto start = cv::getTickCount();
    int counter = 0;

    if (command == 1) {
        for (int i = 1; i < size; i++) {
            int temp_var = vector[i];
            int j = i - 1;

            while (vector[j] > temp_var && j >= 0) {
                vector[j + 1] = vector[j];
                j--;
                counter++;
            }
            vector[j + 1] = temp_var;
        }
    } else if (command == 0) {
        for (int i = 1; i < size; i++) {
            int temp_var = vector[i];
            int j = i - 1;

            while (vector[j] < temp_var && j >= 0) {
                vector[j + 1] = vector[j];
                j--;
                counter++;
            }
            vector[j + 1] = temp_var;
        }
    }

    auto finish = cv::getTickCount();
    double duration = (finish - start) / cv::getTickFrequency();
    std::cout << "Time taken by function: " << duration << " microseconds" << std::endl;

    std::cout << "It was " << counter << " steps to the result." << std::endl;
    return vector;
} 
