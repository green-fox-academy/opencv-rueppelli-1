//
// Created by EXEC_NOIR on 1/29/2019.
//

#include "DetectCircles.h"


int detectCircle(cv::Mat img) {
int result;


    if (!img.empty()) {
        cv::Mat gray;
        cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

        cv::GaussianBlur(gray, gray, cv::Size(5, 5), 0, 0);

        std::vector<cv::Vec3f> circles;
        cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows / 6, 100, 30, 0, 0);

        for (size_t i = 0; i < circles.size(); i++) {
            cv::Vec3i c = circles[i];
            cv::Point center = cv::Point(c[0], c[1]);
            circle(img, center, 1, cv::Scalar(0, 100, 100), 3, cv::LINE_AA);
            int radius = c[2];
            circle(img, center, radius, cv::Scalar(255, 0, 255), 3, cv::LINE_AA);

            int centerX = c[0];
            int centerY = c[1];
            char buffer[11];
            sprintf(buffer, "area = %d", radius*radius);
            cv::putText(img, buffer, cv::Point(centerX - radius/2, centerY - radius/2), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(165,115,147), 1, 8, false );
            char buffer2[11];
            sprintf(buffer, "X = %d", c[0]);
            sprintf(buffer2, "Y = %d", c[1]);
            cv::putText(img, buffer, cv::Point(centerX - radius/2, centerY + radius/4), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(165,115,147), 1, 8, false );
            cv::putText(img, buffer2, cv::Point(centerX - radius/4, centerY + radius/2), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(165,115,147), 1, 8, false );

        }
        result = circles.size();
    }else{
        return -1;
    }




    return result;

}