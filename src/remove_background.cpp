#include "remove_background.h"

cv::Mat removeLight(cv::Mat image, cv::Mat pattern)
{
    return pattern - image;
}

cv::Mat removeLightWithDivision(cv::Mat image, cv::Mat pattern)
{
    return 255 * (1 - (pattern / image));
}

void thresholding (cv::Mat image, cv::Mat dst)
{
    cv::threshold( image, dst, 130, 212, cv::THRESH_BINARY );
    imshow( "Threshold", dst );
}

void thresholdingInv (cv::Mat image, cv::Mat dst)
{
    cv::threshold( image, dst, 212, 100, cv::THRESH_BINARY_INV );
    imshow( "Threshold INV", dst );
}

cv::Mat createLightPattern(cv::Mat image)
{
    cv::Mat pattern;
    cv::blur(image, pattern, cv::Size(image.cols / 3, image.rows / 3));
    imshow("LightPatternPhoto", pattern);

    return pattern;
}

void sharpening(cv::Mat image, cv::Mat dst)
{
    cv::Mat kernel = (cv::Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    cv::filter2D(image, dst, -1/CV_64F, kernel);
    imshow("Sharpened Photo", dst);
}