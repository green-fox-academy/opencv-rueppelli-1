#include <opencv2/core/utility.hpp>
#include <sysinfoapi.h>
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
