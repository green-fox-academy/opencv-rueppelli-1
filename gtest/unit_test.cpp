#include <gtest/gtest.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include "detect_circles.h"

TEST(test_check, no_circle)
{

    cv::Mat img = cv::imread("../../img/purple.jpg",cv::IMREAD_GRAYSCALE);

    EXPECT_EQ(detectCircle(img), 0);
}

TEST(test_check, numerous_circle)
{

    cv::Mat img = cv::imread("../../img/ball.jpg", cv::IMREAD_GRAYSCALE);

    EXPECT_EQ(detectCircle(img), 3);
}

TEST(test_check, overlaying_circle)
{

    cv::Mat img = cv::imread("../../img/balls11.jpg", cv::IMREAD_GRAYSCALE);

    EXPECT_EQ(detectCircle(img), 3);
}
