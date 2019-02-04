#ifndef OPENCV1_PROJECT_IMAGE_BLURING_H
#define OPENCV1_PROJECT_IMAGE_BLURING_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <cstdlib>
#include <opencv2/core/core.hpp>

extern cv::Mat img;
extern cv::Mat smoothed_img;
extern int v_median;
extern int v_gaussian;

void gaussian(int, void *);
void median(int, void *);
void bluring_image();

#endif //OPENCV1_PROJECT_IMAGE_BLURING_H
