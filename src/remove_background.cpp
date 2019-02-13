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