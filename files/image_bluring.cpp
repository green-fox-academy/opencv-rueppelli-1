#include <opencv2/opencv.hpp>
#include "image_bluring.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <cstdlib>
#include <opencv2/core/core.hpp>



void gaussian(int, void *) {
    GaussianBlur(img, smoothed_img, cv::Size(2 * v_gaussian + 1, 2 * v_gaussian + 1), v_gaussian);
    imshow("Project Picture", smoothed_img);
}

void median(int, void *) {
    medianBlur(img, smoothed_img, 2 * v_median + 1);
    imshow("Project Picture", smoothed_img);
}

void bluring_image (){
    cv::createTrackbar("Gaussian", "Project Picture", &v_gaussian, 25, gaussian);
    gaussian(1, nullptr);

    cv::createTrackbar("Median", "Project Picture", &v_median, 25, median);
    median(1, nullptr);
}









