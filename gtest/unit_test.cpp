#include <gtest/gtest.h>
#include "../src/initial.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include "../src/DetectCircles.h"

TEST(test_check, empty_test){

    cv::Mat img = cv::imread("");

    EXPECT_EQ(detectCircle(img), -1);
}

TEST(test_check, no_circle){

    cv::Mat img = cv::imread("../../img/purple.jpg");

    EXPECT_EQ(detectCircle(img), 0);
}

TEST(test_check, numerous_circle){

    cv::Mat img = cv::imread("../../img/ball.jpg");

    EXPECT_EQ(detectCircle(img), 3);
}

TEST(test_check, overlaying_circle){

    cv::Mat img = cv::imread("../../img/balls11.jpg");

    EXPECT_EQ(detectCircle(img), 3);
}




