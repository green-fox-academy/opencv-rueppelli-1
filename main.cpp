#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <cstdlib>
#include <iostream>
#include "initial.h"
#include "DetectCircles.h"
#include "image_bluring.h"

cv::Mat img;
cv::Mat smoothed_img;
int v_median = 0;
int v_gaussian = 0;

int main()
{
    std::string imagePath = "..\\img\\ball.jpg";
    img = cv::imread( imagePath, 1);

    if (!img.data) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    cv::namedWindow("Project Picture", 1);

    //bluring_image();
    std::cout << detectCircle() << std::endl;
    imshow( "Project Picture", img );


    cv::waitKey(0);
    return 0;
};
