#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <opencv2/core/utility.hpp>

#include "detect_circles.h"
#include "database_handler.h"
#include "remove_background.h"
#include "sorting.h"
#include "histogram.h"

cv::Mat img;
cv::Mat smoothed_img;
cv::Mat shapes;
int v_median = 0;
int v_gaussian = 0;

void gaussian(int, void *);
void median(int, void *);
void bluring_image();

int main(int argc, char* argv[])
{
    img = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    shapes = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);

    if (!img.data) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    cv::namedWindow("Project Picture", cv::WINDOW_NORMAL );
    cv::imshow("Project Picture", img);
    cv::namedWindow("SHAPES", cv::WINDOW_AUTOSIZE);
    cv::imshow("SHAPES", shapes);
    cv::waitKey();

    cv::Mat pattern = createLightPattern(shapes);
    shapes = removeLight(shapes, pattern);
    cv::namedWindow("Remove Light", cv::WINDOW_AUTOSIZE);
    cv::imshow("Remove Light", shapes);
    cv::waitKey();

    thresholding(shapes, shapes);
    cv::namedWindow("Thresholding", cv::WINDOW_AUTOSIZE);
    cv::imshow("Thresholding", shapes);
    cv::waitKey();

    shapes = segmentationStats(shapes);
    cv::namedWindow("Segmentation Stats", cv::WINDOW_AUTOSIZE);
    cv::imshow("Segmentation Stats", shapes);
    cv::waitKey();

    cv::namedWindow("Detect Circles", 1);
    clock_t start, end;
    start = clock();
    int circleAmount = detectCircle(img);
    end = clock();
    double processingTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    //createRecord("../files/CircleDetectionDatabase.db", "Circles", imagePath, processingTime, circleAmount);
    imshow("Detect Circles", img);

    cv::waitKey(0) ;

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
