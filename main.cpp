#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <chrono>

#include "initial.h"
#include "detect_circles.h"
#include "database_handler.h"
#include "sorting.h"

cv::Mat img;
cv::Mat smoothed_img;
int v_median = 0;
int v_gaussian = 0;

void gaussian(int, void *);
void median(int, void *);
void bluring_image();

int main()
{
    int array[] = { 5, 3, 7, 14, 10, 6, 42 };
    int size = sizeof(array)/ sizeof(array[0]);
    insertion_sort(array, size, 1);
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::vector<int> vector = { 5, 3, 7, 14, 10, 6, 42};
    insertion_sort(vector, static_cast<int>(vector.size()), 1);
    for (int j = 0; j < vector.size(); j++) {
        std::cout << vector[j] << " ";
    }
  
    std::string imagePath = "..\\img\\ball.jpg";
    img = cv::imread( imagePath, cv::IMREAD_GRAYSCALE);

    if (!img.data) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    cv::namedWindow("Project Picture", 1);
    clock_t start, end;
    readDataBase("../files/CircleDetectionDatabase.db");
    start = clock();
    int circleAmount = detectCircle(img);
    end = clock();
    double processingTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    createRecord("../files/CircleDetectionDatabase.db", "Circles", imagePath, processingTime, circleAmount);
    imshow("Project Picture", img);

    cv::waitKey(0);

    return 0;
}

void gaussian(int, void *)
{
    GaussianBlur(img, smoothed_img, cv::Size(2 * v_gaussian + 1, 2 * v_gaussian + 1), v_gaussian);
    imshow("Project Picture", smoothed_img);
}

void median(int, void *)
{
    cv::medianBlur(img, smoothed_img, 2 * v_median + 1);
    imshow("Project Picture", smoothed_img);
}

void bluring_image ()
{
    cv::createTrackbar("Gaussian", "Project Picture", &v_gaussian, 25, gaussian);
    gaussian(1, nullptr);

    cv::createTrackbar("Median", "Project Picture", &v_median, 25, median);
    median(1, nullptr);
    cv::waitKey();
}
