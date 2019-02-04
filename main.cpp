#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <cstdlib>
#include <iostream>
#include "initial.h"
#include "DetectCircles.h"
#include "image_bluring.h"
#include "crud.h"
#include <time.h>

cv::Mat img;
cv::Mat smoothed_img;
int v_median = 0;
int v_gaussian = 0;

int main()
{
    std::string imagePath = "..\\img\\kek.png";
    img = cv::imread( imagePath, 1);

    if (!img.data) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    cv::namedWindow("Project Picture", 1);
    clock_t start, end;
    readDataBase("../files/CircleDetectionDatabase.db");

    start = clock();
    int circleAmount = detectCircle(img);
    end = clock();
    double processingTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    createRecord("../files/CircleDetectionDatabase.db", "Circles", imagePath, processingTime, circleAmount);

    imshow( "Project Picture", img );

    cv::waitKey(0);

    return 0;
};
