#ifndef OPENCV_RUEPELLI_1_REMOVE_BACKGROUND_H
#define OPENCV_RUEPELLI_1_REMOVE_BACKGROUND_H

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

cv::Mat removeLight(cv::Mat image, cv::Mat pattern);
cv::Mat removeLightWithDivision(cv::Mat image, cv::Mat pattern);

#endif //OPENCV_RUEPELLI_1_REMOVE_BACKGROUND_H
