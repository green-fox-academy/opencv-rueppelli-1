//
// Created by Gé on 2019. 02. 14..
//

#ifndef OPENCV_RUEPELLI_1_HISTOGRAM_H
#define OPENCV_RUEPELLI_1_HISTOGRAM_H
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

cv::Mat createHistogram(cv::Mat image);
cv::Mat normalize(cv::Mat img);

#endif //OPENCV_RUEPELLI_1_HISTOGRAM_H
