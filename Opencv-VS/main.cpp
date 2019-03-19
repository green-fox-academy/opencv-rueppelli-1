#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <iostream>

#include "detect_circles.h"
#include "database_handler.h"
#include "image_manipulation.h"
#include "sorting.h"
#include "histogram.h"

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread(argv[3], cv::IMREAD_COLOR);
    cv::Mat shapes = cv::imread(argv[4], cv::IMREAD_GRAYSCALE);

    if (!img.data || !shapes.data) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    cv::waitKey(0) ;
    return 0;
}
