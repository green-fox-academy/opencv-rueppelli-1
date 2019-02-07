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

cv::Mat src;
cv::Mat dst;
int v_median = 0;
int v_gaussian = 0;

void gaussian(int, void *);
void median(int, void *);
void bluring_image();
static void threshold_binary( int, void* );
static void threshold_binary_inv( int, void* );

int main()
{
    int x = 0;
    int y = 0;
    std::string imagePath = "..\\img\\ball.jpg";
    src = cv::imread( imagePath, cv::IMREAD_GRAYSCALE);

    if (!src.data) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    cv::namedWindow("Project Picture", 1);
    /*clock_t start, end;
    readDataBase("../files/CircleDetectionDatabase.db");
    start = clock();
    int circleAmount = detectCircle(src);
    end = clock();
    double processingTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    createRecord("../files/CircleDetectionDatabase.db", "Circles", imagePath, processingTime, circleAmount);*/
    imshow("Project Picture", src);

    cv::namedWindow("Threshold", 1);
    cv::moveWindow("Threshold", x += 50, y += y);
    cv::moveWindow("Threshold INV", x += 50, y += y);
    threshold_binary(0, nullptr);
    threshold_binary_inv(0, nullptr);

    cv::waitKey(0);

    return 0;
}

static void threshold_binary( int, void* )
{
    int threshold_value = 110;
    int threshold_type = 0;
    int const max_binary_value = 255;
    threshold( src, dst, threshold_value, max_binary_value, threshold_type );
    imshow( "Threshold", dst );
}

static void threshold_binary_inv( int, void* )
{
    int threshold_value = 110;
    int threshold_type = 1;
    int const max_binary_value = 255;
    threshold( src, dst, threshold_value, max_binary_value, threshold_type );
    imshow( "Threshold INV", dst );
}

void gaussian(int, void *)
{
    GaussianBlur(src, dst, cv::Size(2 * v_gaussian + 1, 2 * v_gaussian + 1), v_gaussian);
    imshow("Project Picture", dst);
}

void median(int, void *)
{
    cv::medianBlur(src, dst, 2 * v_median + 1);
    imshow("Project Picture", dst);
}

void bluring_image ()
{
    cv::createTrackbar("Gaussian", "Project Picture", &v_gaussian, 25, gaussian);
    gaussian(1, nullptr);

    cv::createTrackbar("Median", "Project Picture", &v_median, 25, median);
    median(1, nullptr);
    cv::waitKey();
}
