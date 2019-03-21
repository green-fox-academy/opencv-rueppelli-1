#include "detect_circles.h"

cv::Mat detectCircle(cv::Mat img)
{
    int numberOfCircles;
	//cv::GaussianBlur(img, img, cv::Size(7, 7), 0, 0);
	cv::medianBlur(img, img, 7);
	cvtColor(img, img, cv::COLOR_BGR2GRAY);

    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(img, circles, cv::HOUGH_GRADIENT, 1, img.rows / 4, 50, 130, 0, 0);

    cv::Mat maskedImage;
    cv::Mat mask(img.rows, img.cols, img.type(), cv::Scalar(0,0,0));

    for(size_t i = 0; i < circles.size(); i++){
        cv::Vec3i c = circles[i];
        cv::Point center = cv::Point(c[0], c[1]);
        int radius = c[2];

        circle(img, center, radius, cv::Scalar(255, 255, 0), 3, cv::LINE_AA);

        int centerX = c[0];
        int centerY = c[1];
        char buffer[11];
        sprintf(buffer, "area = %d", radius * radius);
       // cv::putText(img, buffer, cv::Point(centerX - radius / 2, centerY - radius / 2), cv::FONT_HERSHEY_SIMPLEX, 0.5,
                  //  cv::Scalar(255, 255, 255), 2, 8, false);
        char buffer2[11];
        sprintf(buffer, "X = %d", c[0]);
        sprintf(buffer2, "Y = %d", c[1]);
       // cv::putText(img, buffer, cv::Point(centerX - radius / 2, centerY + radius / 4), cv::FONT_HERSHEY_SIMPLEX, 0.5,
               //     cv::Scalar(255, 255, 255), 2, 8, false);
       // cv::putText(img, buffer2, cv::Point(centerX - radius / 4, centerY + radius / 2), cv::FONT_HERSHEY_SIMPLEX, 0.5,
                //    cv::Scalar(255, 255, 255), 2, 8, false);
    }
	numberOfCircles = circles.size();

    for(size_t i = 0; i < numberOfCircles; i++){
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        circle( mask, center, radius, cv::Scalar(255,255,255), -1, 8);
    }
    img.copyTo(maskedImage, mask);
    imshow("Detected Circles on masked image", maskedImage);

    return maskedImage;
}
