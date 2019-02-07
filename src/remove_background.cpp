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
    cv::threshold( image, dst, 110, 255, cv::THRESH_BINARY );
    imshow( "Threshold", dst );
}

void thresholdingInv (cv::Mat image, cv::Mat dst)
{
    cv::threshold( image, dst, 110, 255, cv::THRESH_BINARY_INV );
    imshow( "Threshold INV", dst );
}