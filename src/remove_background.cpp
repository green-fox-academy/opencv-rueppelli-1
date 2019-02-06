#include "remove_background.h"

cv::Mat removeLight(cv::Mat image, cv::Mat pattern)
{
    return pattern - image;
}
cv::Mat removeLightWithDivision(cv::Mat image, cv::Mat pattern)
{
    return 255 * (1 - (pattern / image));
}
