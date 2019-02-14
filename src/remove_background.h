#ifndef OPENCV_RUEPELLI_1_REMOVE_BACKGROUND_H
#define OPENCV_RUEPELLI_1_REMOVE_BACKGROUND_H

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "sorting.h"

cv::Mat removeLight(cv::Mat image, cv::Mat pattern);
cv::Mat removeLightWithDivision(cv::Mat image, cv::Mat pattern);
void thresholding (cv::Mat image, cv::Mat dst);
void thresholdingInv (cv::Mat image, cv::Mat dst);
cv::Mat createLightPattern(cv::Mat image);
void sharpening(cv::Mat image, cv::Mat dst);
cv::Mat segmentation(cv::Mat segmentImage);
cv::Mat segmentationStats(cv::Mat segmentImage);

#endif //OPENCV_RUEPELLI_1_REMOVE_BACKGROUND_H
