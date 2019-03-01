#ifndef OPENCV_RUEPELLI_1_REMOVE_BACKGROUND_H
#define OPENCV_RUEPELLI_1_REMOVE_BACKGROUND_H

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "sorting.h"
#include <vector>
#include <opencv2/features2d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>


cv::Mat removeLight(cv::Mat image, cv::Mat pattern);
cv::Mat removeLightWithDivision(cv::Mat image, cv::Mat pattern);
void thresholding (cv::Mat image, cv::Mat dst);
void thresholdingInv (cv::Mat image, cv::Mat dst);
cv::Mat createLightPattern(cv::Mat image);
void sharpening(cv::Mat image);
cv::Mat segmentation(cv::Mat segmentImage);
cv::Mat segmentationStats(cv::Mat segmentImage);
cv::Mat akazeDetection (cv::Mat image);
cv::Mat fastFeatureDetection(cv::Mat image);
cv::Mat binarizeImageOtsu(cv::Mat image);

#endif //OPENCV_RUEPELLI_1_REMOVE_BACKGROUND_H
