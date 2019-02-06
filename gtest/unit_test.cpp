#include <gtest/gtest.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <time.h>
#include <opencv2/core/core.hpp>
#include "detect_circles.h"
#include "sorting.h"

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
    int size = rand()%1000+1;

    int selectionArray[size];
    int insertionArray[size];
    int quickArray[size];

    int elements;
    for (int i = 0; i < size-1; ++i) {
        elements = rand()%1000+1;

        selectionArray[i] = elements;
        insertionArray[i] = elements;
        quickArray[i] = elements;
    }

    int selectionCounter = 0;
    int insertionCounter = 0;
    int quickCounter = 0;

    int* newSelectionSort = selectionSort(selectionArray, size, selectionCounter);
    int* newInsertionSort = insertion_sort(insertionArray, size, insertionCounter);
    int* newQuickSort = quickSort(quickArray, 0, size-1, quickCounter);


    ASSERT_LT(selectionCounter, quickCounter);
}

TEST(FastestSortingSteps, decreasingArray)
{
    srand(time(nullptr));
    int size = rand()%1000+1;

    int selectionArray[size];
    int insertionArray[size];
    int quickArray[size];

    int elements;
    for (int i = 0; i < size-1; ++i) {
        elements = rand()%1000+1;

        selectionArray[i] = elements;
        insertionArray[i] = elements;
        quickArray[i] = elements;
    }

    int selectionCounter = 0;
    int insertionCounter = 0;
    int quickCounter = 0;

    int* newSelectionSort = selectionSort(selectionArray, size, selectionCounter, 0);
    int* newInsertionSort = insertion_sort(insertionArray, size, insertionCounter, 0);
    int* newQuickSort = quickSort(quickArray, 0, size-1, quickCounter, 0);


    ASSERT_LT(selectionCounter, quickCounter);
}
