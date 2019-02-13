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

int *insertionSort(int *array, int size, int &counter, int command)
{
    auto start = cv::getTickCount();
    counter = 0;
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
   // std::cout << "Time taken by function: " << duration << " microseconds" << std::endl;

   // std::cout << "It was " << counter << " steps to the result." << std::endl;
    return array;
}

std::vector<int> insertionSort(std::vector<int> vector, int size, int &counter, int command)
{
    auto start = cv::getTickCount();
    counter = 0;

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
  //  std::cout << "Time taken by function: " << duration << " microseconds" << std::endl;

  //  std::cout << "It was " << counter << " steps to the result." << std::endl;
    return vector;
}

void merge(int* array, int low, int middle, int high, int order)
{
    int i;
    int j;
    int k;

    int size1 = middle - low + 1;
    int size2 = high - middle;

    int temp1[size1];
    int temp2[size2];

    for(i = 0; i < size1; i++ ){
        temp1[i] = array[low + i];
    }
    for(j = 0; j < size2; j++){
        temp2[j] = array[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = low;
    if(order == 1) {

        while (i < size1 && j < size2) {
            if (temp1[i] <= temp2[j]) {
                array[k] = temp1[i];
                i++;
            } else {
                array[k] = temp2[j];
                j++;
            }
            k++;
        }
    }else{
        while (i < size1 && j < size2) {
            if (temp1[i] >= temp2[j]) {
                array[k] = temp1[i];
                i++;
            } else {
                array[k] = temp2[j];
                j++;
            }
            k++;
        }
    }
    while (i < size1)
    {
        array[k] = temp1[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        array[k] = temp2[j];
        j++;
        k++;
    }
}

void mergeSort(int* array, int low, int high, int order)
{
    if(low < high)
    {
        int middle = low+(high-low)/2;

        mergeSort(array, low, middle, order);
        mergeSort(array, middle+1, high, order);

        merge(array, low, middle, high, order);
    }
}
void merge(std::vector<int> &vector, int low, int middle, int high, int order)
{
    int i;
    int j;
    int k;

    int size1 = middle - low + 1;
    int size2 = high - middle;

    int temp1[size1];
    int temp2[size2];

    for(i = 0; i < size1; i++ ){
        temp1[i] = vector[low + i];
    }
    for(j = 0; j < size2; j++){
        temp2[j] = vector[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = low;
    if(order == 1) {

        while (i < size1 && j < size2) {
            if (temp1[i] <= temp2[j]) {
                vector[k] = temp1[i];
                i++;
            } else {
                vector[k] = temp2[j];
                j++;
            }
            k++;
        }
    }else{
        while (i < size1 && j < size2) {
            if (temp1[i] >= temp2[j]) {
                vector[k] = temp1[i];
                i++;
            } else {
                vector[k] = temp2[j];
                j++;
            }
            k++;
        }
    }
    while (i < size1)
    {
        vector[k] = temp1[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        vector[k] = temp2[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &vector, int low, int high, int order)
{
    if(low < high)
    {
        int middle = low+(high-low)/2;

        mergeSort(vector, low, middle, order);
        mergeSort(vector, middle+1, high, order);

        merge(vector, low, middle, high, order);
    }
}
