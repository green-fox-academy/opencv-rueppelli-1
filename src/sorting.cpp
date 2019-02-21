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
    quickSortVector(sorted, low, high, counter, order);
    return sorted;
}

int* quickSort(int* array, int low, int high, int &counter, int order)
{
    int* sorted = array;
    quickSortArray(sorted, low, high, counter, order);
    return sorted;
}

void quickSortVector(std::vector<int> &unsorted, int low, int high, int &counter, int order)
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
            quickSortVector(unsorted, i, high, counter, 1);
        }
        if (j > low) {
            quickSortVector(unsorted, low, j, counter, 1);
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
            quickSortVector(unsorted, low, j, counter, 0);
        }
        if (i < high) {
            quickSortVector(unsorted, i, high, counter, 0);
        }
    }
}

void quickSortArray(int *array, int low, int high, int &counter, int order)
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
            quickSortArray(array, low, j, counter, order);
        }
        if (i < high) {
            quickSortArray(array, i, high, counter, order);
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
            quickSortArray(array, low, j, counter, order);
        }
        if (i < high) {
            quickSortArray(array, i, high, counter, order);
        }
    }else{
        return quickSortArray(array, low, high, counter, 1);
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
    return vector;
}

void merge(int* array, int low, int middle, int high, int &counter, int order)
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
                counter++;
            } else {
                array[k] = temp2[j];
                j++;
                counter++;
            }
            k++;
        }
    }else{
        while (i < size1 && j < size2) {
            if (temp1[i] >= temp2[j]) {
                array[k] = temp1[i];
                i++;
                counter++;
            } else {
                array[k] = temp2[j];
                j++;
                counter++;
            }
            k++;
        }
    }
    while (i < size1)
    {
        array[k] = temp1[i];
        i++;
        k++;
        counter++;
    }

    while (j < size2)
    {
        array[k] = temp2[j];
        j++;
        k++;
        counter++;
    }
}

void mergeSortInit(int* array, int low, int high, int &counter, int order)
{
    if(low < high)
    {
        int middle = low+(high-low)/2;

        mergeSortInit(array, low, middle, counter, order);
        mergeSortInit(array, middle+1, high, counter, order);

        merge(array, low, middle, high, counter, order);
    }
}
void merge(std::vector<int> &vector, int low, int middle, int high, int &counter, int order)
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
                counter++;
            } else {
                vector[k] = temp2[j];
                j++;
                counter++;
            }
            k++;
        }
    }else{
        while (i < size1 && j < size2) {
            if (temp1[i] >= temp2[j]) {
                vector[k] = temp1[i];
                i++;
                counter++;
            } else {
                vector[k] = temp2[j];
                j++;
                counter++;
            }
            k++;
        }
    }
    while (i < size1)
    {
        vector[k] = temp1[i];
        i++;
        k++;
        counter++;
    }

    while (j < size2)
    {
        vector[k] = temp2[j];
        j++;
        k++;
        counter++;
    }
}

void mergeSortInit(std::vector<int> &vector, int low, int high, int &counter, int order)
{
    if(low < high)
    {
        int middle = low+(high-low)/2;

        mergeSortInit(vector, low, middle, counter, order);
        mergeSortInit(vector, middle+1, high, counter, order);

        merge(vector, low, middle, high, counter, order);
    }
}

std::vector<int> mergeSort(std::vector<int> unsorted, int low, int high, int &counter, int order)
{
    std::vector<int> sorted = unsorted;
    mergeSortInit(sorted, low, high, counter, order);
    return sorted;
}

int* mergeSort(int *unsorted, int low, int high, int &counter, int order)
{
    int* sorted = unsorted;
    mergeSortInit(sorted, low, high, counter, order);
    return sorted;
}

int *shellSort(int *array, int size, int &counter, int command) {
    auto start = cv::getTickCount();
    counter = 0;
    int i, j, shell, temp_array;
    shell = size / 2;

    if (command == 1) {
        while (shell > 0) {
            i = shell;
            while (i < size) {
                temp_array = array[i];

                for (j = i; (j >= shell) && (array[j - shell] > temp_array); j -= shell) {
                    array[j] = array[j - shell];
                    counter++;
                }
                array[j] = temp_array;
                i++;
                counter++;
            }
            shell = shell / 2;
        }
    } else if (command == 0) {
        while (shell > 0) {
            i = shell;
            while (i < size) {
                temp_array = array[i];

                for (j = i; (j >= shell) && (array[j - shell] < temp_array); j -= shell) {
                    array[j] = array[j - shell];
                    counter++;
                }
                array[j] = temp_array;
                i++;
                counter++;
            }
            shell = shell / 2;
        }
    }

    auto finish = cv::getTickCount();
    double duration = (finish - start) / cv::getTickFrequency();
    return array;
}

std::vector<int> shellSort(std::vector<int> &vector, int size, int &counter, int command) {
    auto start = cv::getTickCount();
    counter = 0;
    int i, j, shell, tempVector;
    shell = size / 2;

    if (command == 1) {
        while (shell > 0) {
            i = shell;
            while (i < size) {
                tempVector = vector[i];

                for (j = i; (j >= shell) && (vector[j - shell] > tempVector); j -= shell) {
                    vector[j] = vector[j - shell];
                    counter++;
                }
                vector[j] = tempVector;
                i++;
                counter++;
            }
            shell = shell / 2;
        }
    } else if (command == 0) {
        while (shell > 0) {
            i = shell;
            while (i < size) {
                tempVector = vector[i];

                for (j = i; (j >= shell) && (vector[j - shell] < tempVector); j -= shell) {
                    vector[j] = vector[j - shell];
                    counter++;
                }
                vector[j] = tempVector;
                i++;
                counter++;
            }
            shell = shell / 2;
        }
    }

    auto finish = cv::getTickCount();
    double duration = (finish - start) / cv::getTickFrequency();
    return vector;
}

void heapify(int myArray[], int size, int x, int &counter, int order)
{
    int temp;
    int largest = x;
    int leftChild = 2 * x + 1;
    int rightChild = 2 * x + 2;

    if(order == 1){
        if (leftChild < size && myArray[leftChild] > myArray[largest]) {
            largest = leftChild;
            counter++;
        }
        if (rightChild < size && myArray[rightChild] > myArray[largest]) {
            largest = rightChild;
            counter++;
        }
        if (largest != x) {
            temp = myArray[x];
            myArray[x] = myArray[largest];
            myArray[largest] = temp;
            heapify(myArray, size, largest, counter);
            counter++;
        }
    }else{
        if (leftChild < size && myArray[leftChild] < myArray[largest]) {
            largest = leftChild;
            counter++;
        }
        if (rightChild < size && myArray[rightChild] < myArray[largest]) {
            largest = rightChild;
            counter++;
        }
        if (largest != x) {
            temp = myArray[x];
            myArray[x] = myArray[largest];
            myArray[largest] = temp;
            heapify(myArray, size, largest, counter, 0);
            counter++;
        }
    }
}

void heapSortInit(int myArray[], int size, int &counter, int order)
{
    int temp;
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(myArray, size, i, counter, order);
    for (int i = size - 1; i >= 0; i--) {
        temp = myArray[0];
        myArray[0] = myArray[i];
        myArray[i] = temp;
        heapify(myArray, i, 0, counter, order);
        counter++;
    }
}

int* heapSort(int unsorted[], int size, int &counter, int order)
{
    int* sorted = unsorted;
    heapSortInit(sorted, size, counter, order);
    return sorted;
}

void heapify(std::vector<int> &myVector, int size, int x, int &counter, int order)
{
    int temp;
    int largest = x;
    int leftChild = 2 * x + 1;
    int rightChild = 2 * x + 2;

    if(order == 1){
        if (leftChild < size && myVector[leftChild] > myVector[largest]) {
            largest = leftChild;
            counter++;
        }
        if (rightChild < size && myVector[rightChild] > myVector[largest]) {
            largest = rightChild;
            counter++;
        }
        if (largest != x) {
            temp = myVector[x];
            myVector[x] = myVector[largest];
            myVector[largest] = temp;
            heapify(myVector, size, largest, counter);
            counter++;
        }
    }else{
        if (leftChild < size && myVector[leftChild] < myVector[largest]) {
            largest = leftChild;
            counter++;
        }
        if (rightChild < size && myVector[rightChild] < myVector[largest]) {
            largest = rightChild;
            counter++;
        }
        if (largest != x) {
            temp = myVector[x];
            myVector[x] = myVector[largest];
            myVector[largest] = temp;
            heapify(myVector, size, largest, counter, 0);
            counter++;
        }
    }
}

void heapSortInit(std::vector<int> &myVector, int size, int &counter, int order)
{
    int temp;
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(myVector, size, i, counter, order);
    for (int i = size - 1; i >= 0; i--) {
        temp = myVector[0];
        myVector[0] = myVector[i];
        myVector[i] = temp;
        heapify(myVector, i, 0, counter, order);
        counter++;
    }
}

std::vector<int> heapSort(std::vector<int> unsorted, int size, int &counter, int order)
{
    std::vector<int> sorted = std::move(unsorted);
    heapSortInit(sorted, size, counter, order);
    return sorted;
}
