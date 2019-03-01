#include <gtest/gtest.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <time.h>
#include <opencv2/core/core.hpp>
#include "detect_circles.h"
#include "sorting.h"
#include <opencv2/core/utility.hpp>


TEST(test_check, no_circle)
{

    cv::Mat img = cv::imread("../../img/purple.jpg",cv::IMREAD_GRAYSCALE);

    EXPECT_EQ(detectCircle(img), 0);
}

TEST(test_check, numerous_circle)
{

    cv::Mat img = cv::imread("../../img/ball.jpg", cv::IMREAD_GRAYSCALE);

    EXPECT_EQ(detectCircle(img), 3);
}

TEST(test_check, overlaying_circle)
{

    cv::Mat img = cv::imread("../../img/balls11.jpg", cv::IMREAD_GRAYSCALE);

    EXPECT_EQ(detectCircle(img), 3);
}

TEST(FastestSortingSteps, increasingArray)
{
    srand(time(nullptr));
    int size = rand() % 1000 + 1;

    int selectionArray[size];
    int insertionArray[size];
    int quickArray[size];

    int elements;
    for (int i = 0; i < size - 1; ++i) {
        elements = rand() % 1000 + 1;

        selectionArray[i] = elements;
        insertionArray[i] = elements;
        quickArray[i] = elements;
    }

    int selectionCounter = 0;
    int insertionCounter = 0;
    int quickCounter = 0;

    int* newSelectionSort = selectionSort(selectionArray, size, selectionCounter);
    int* newInsertionSort = insertionSort(insertionArray, size, insertionCounter);
    int* newQuickSort = quickSort(quickArray, 0, size - 1, quickCounter);


    ASSERT_LT(selectionCounter, quickCounter);
}

TEST(FastestSortingSteps, decreasingArray)
{
    srand(time(nullptr));
    int size = rand() % 1000 + 1;

    int selectionArray[size];
    int insertionArray[size];
    int quickArray[size];

    int elements;
    for (int i = 0; i < size - 1; ++i) {
        elements = rand() % 1000 + 1;

        selectionArray[i] = elements;
        insertionArray[i] = elements;
        quickArray[i] = elements;
    }

    int selectionCounter = 0;
    int insertionCounter = 0;
    int quickCounter = 0;

    int* newSelectionSort = selectionSort(selectionArray, size, selectionCounter, 0);
    int* newInsertionSort = insertionSort(insertionArray, size, insertionCounter, 0);
    int* newQuickSort = quickSort(quickArray, 0, size - 1, quickCounter, 0);


    ASSERT_LT(selectionCounter, quickCounter);
}

TEST(FastestSortingTime, increasingArray)
{


    srand(time(nullptr));
    int size = rand() % 1000 + 1;

    int selectionArray[size];
    int insertionArray[size];
    int quickArray[size];

    int elements;
    for (int i = 0; i < size - 1; ++i) {
        elements = rand() % 1000 + 1;

        selectionArray[i] = elements;
        insertionArray[i] = elements;
        quickArray[i] = elements;
    }

    int selectionCounter = 0;
    int insertionCounter = 0;
    int quickCounter = 0;

    auto start = cv::getTickCount();
    int* newSelectionSort = selectionSort(selectionArray, size, selectionCounter);
    auto finish = cv::getTickCount();
    double selectionDuration = (finish - start) / cv::getTickFrequency();

    auto start1 = cv::getTickCount();
    int* newQuickSort = quickSort(quickArray, 0, size-1, quickCounter);
    auto finish1 = cv::getTickCount();
    double quickDuration = (finish1 - start1) / cv::getTickFrequency();

    ASSERT_LT(quickDuration, selectionDuration);
}

TEST(FastestSortingTime, decreasingVector)
{
    srand(time(nullptr));
    int size = rand() % 1000 + 1;

    std::vector<int> selectionVector;
    std::vector<int> quickVector;

    int elements;
    for (int i = 0; i < size - 1; ++i) {
        elements = rand() % 1000 + 1;

        selectionVector.push_back(elements);
        quickVector.push_back(elements);
    }

    int selectionCounter = 0;
    int quickCounter = 0;

    auto start = cv::getTickCount();
    std::vector<int> newSelectionSort = selectionSort(selectionVector, selectionCounter, 0);
    auto finish = cv::getTickCount();
    double selectionDuration = (finish - start) / cv::getTickFrequency();

    auto start1 = cv::getTickCount();
    std::vector<int> newQuickSort = quickSort(quickVector, 0, size-1, quickCounter, 0);
    auto finish1 = cv::getTickCount();
    double quickDuration = (finish1 - start1) / cv::getTickFrequency();

    ASSERT_LT(selectionDuration, quickDuration);
}

TEST(FastestSortingTime, increasingVector)
{
    srand(time(nullptr));
    int size = rand() % 1000 + 1;

    std::vector<int> selectionVector;
    std::vector<int> quickVector;

    int elements;
    for (int i = 0; i < size - 1; ++i) {
        elements = rand() % 1000 + 1;

        selectionVector.push_back(elements);
        quickVector.push_back(elements);
    }

    int selectionCounter = 0;
    int quickCounter = 0;

    auto start = cv::getTickCount();
    std::vector<int> newSelectionSort = selectionSort(selectionVector, selectionCounter);
    auto finish = cv::getTickCount();
    double selectionDuration = (finish - start) / cv::getTickFrequency();

    auto start1 = cv::getTickCount();
    std::vector<int> newQuickSort = quickSort(quickVector, 0, size - 1, quickCounter);
    auto finish1 = cv::getTickCount();
    double quickDuration = (finish1 - start1) / cv::getTickFrequency();

    ASSERT_LT(selectionDuration, quickDuration);
}
TEST(InsertionSortTest, increasingVector)
{
    srand(time(nullptr));
    int size = rand() % 100 + 1;
    std::vector<int> myVector;

    int elements;
    for (int i = 0; i < size - 1; ++i) {
        elements = rand() % 100 + 1;
        myVector.push_back(elements);

    }

    int counter = 0;
    std::vector<int> myNumbersInOrder = insertionSort(myVector, static_cast<int>(myVector.size()), counter);

    std::sort(myVector.begin(), myVector.begin()+myVector.size());

    EXPECT_EQ(myNumbersInOrder, myVector);
}

TEST(InsertionSortTest, decreasingVector)
{
    srand(time(nullptr));
    int size = rand() % 100 + 1;
    std::vector<int> myVector;

    int elements;
    for (int i = 0; i < size - 1; ++i) {
        elements = rand() % 100 + 1;
        myVector.push_back(elements);

    }

    int counter = 0;
    std::vector<int> myNumbersInOrder = insertionSort(myVector, static_cast<int>(myVector.size()), counter, 0);

    std::sort(myVector.begin(), myVector.end(), std::greater<>());

    EXPECT_EQ(myNumbersInOrder, myVector);

}

TEST(InsertionSortTest, increasingArray)
{
    srand(time(nullptr));
    int size = rand() % 100 + 1;

    int insertionArray[size];
    int newInsertionArray[size];

    int elements;
    for (int i = 0; i < size; ++i) {
        elements = rand() % 100 + 1;
        newInsertionArray[i] = elements;
        insertionArray[i] = elements;
    }

    int insertionCounter = 0;
    insertionSort(insertionArray, size, insertionCounter);

    int sizeOfArray = sizeof(newInsertionArray)/ sizeof(newInsertionArray[0]);
    std::sort(newInsertionArray, newInsertionArray+sizeOfArray);

    for (int k = 0; k < size; ++k) {
        EXPECT_EQ(insertionArray[k], newInsertionArray[k]);
    }
}

TEST(InsertionSortTest, decreasingArray)
{
    srand(time(nullptr));
    int size = rand() % 100 + 1;

    int insertionArray[size];
    int newInsertionArray[size];

    int elements;
    for (int i = 0; i < size; ++i) {
        elements = rand() % 100 + 1;
        newInsertionArray[i] = elements;
        insertionArray[i] = elements;
    }

    int insertionCounter = 0;
    insertionSort(insertionArray, size, insertionCounter, 0);

    int sizeOfArray = sizeof(newInsertionArray)/ sizeof(newInsertionArray[0]);
    std::sort(newInsertionArray, newInsertionArray+sizeOfArray, std::greater<>());

    for (int k = 0; k < size; ++k) {
        EXPECT_EQ(insertionArray[k], newInsertionArray[k]);
    }
}

TEST(MergeSortTest, increasingArray)
{
    srand(time(nullptr));
    int size = rand() % 100 + 1;

    int mergeArray[size];
    int mergeNewArray[size];

    int elements;
    for (int i = 0; i < size; ++i) {
        elements = rand() % 100 + 1;
        mergeNewArray[i] = elements;
        mergeArray[i] = elements;
    }

    int mergeCounter = 0;
    mergeSort(mergeArray, 0, size - 1, mergeCounter, 1);

    int sizeOfArray = sizeof(mergeNewArray)/ sizeof(mergeNewArray[0]);
    std::sort(mergeNewArray, mergeNewArray+sizeOfArray);

    for (int k = 0; k < size; ++k) {
        EXPECT_EQ(mergeArray[k], mergeNewArray[k]);
    }
}

TEST(MergeSortTest, decreasingArray)
{
    srand(time(nullptr));
    int size = rand() % 100 + 1;

    int mergeArray[size];
    int mergeNewArray[size];

    int elements;
    for (int i = 0; i < size; ++i) {
        elements = rand() % 100 + 1;
        mergeNewArray[i] = elements;
        mergeArray[i] = elements;
    }

    int mergeCounter = 0;
    mergeSort(mergeArray, 0, size - 1, mergeCounter, 0);

    int sizeOfArray = sizeof(mergeNewArray)/ sizeof(mergeNewArray[0]);
    std::sort(mergeNewArray, mergeNewArray+sizeOfArray, std::greater<>());

    for (int k = 0; k < size; ++k) {
        EXPECT_EQ(mergeArray[k], mergeNewArray[k]);
    }
}

TEST(MergeSortTest, increasingVector)
{
    srand(time(nullptr));
    int size = rand() % 100 + 1;
    std::vector<int> myVector;

    int elements;
    for (int i = 0; i < size ; ++i) {
        elements = rand() % 100 + 1;
        myVector.push_back(elements);
    }

    int counter = 0;
    std::vector<int> numbersInOrder = mergeSort(myVector, 0, size - 1, counter, 1);
    std::sort(myVector.begin(), myVector.begin() + myVector.size());

    EXPECT_EQ(numbersInOrder, myVector);
}

TEST(MergeSortTest, decreasingVector)
{
    srand(time(nullptr));
    int size = rand() % 100 + 1;
    std::vector<int> myVector;

    int elements;
    for (int i = 0; i < size ; ++i) {
        elements = rand() % 100 + 1;
        myVector.push_back(elements);
    }

    int counter = 0;
    std::vector<int> numbersInOrder = mergeSort(myVector, 0, size - 1, counter, 0);
    std::sort(myVector.begin(), myVector.end(), std::greater<>());

    EXPECT_EQ(numbersInOrder, myVector);
}
