#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <cstdlib>
#include <iostream>
#include "initial.h"

int main()
{
    std::string imagePath = "..\\img\\balsee.jpg";
    cv::Mat img = cv::imread( imagePath, 1);

    if (!img.data) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    cv::namedWindow("Project Picture", 1);

    imshow( "Project Picture", img );

    cv::waitKey(0);
    return 0;
};
