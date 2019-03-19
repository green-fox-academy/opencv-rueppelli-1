#include <msidefs.h>
#include "histogram.h"

cv::Mat createHistogram(cv::Mat img)
{
    std::vector<cv::Mat> BGR;
    cv::split(img, BGR);
    int histogramSize = 256;
    float range[] = {0, 255};
    const float* histRange = {range};
    bool uniform = true;
    bool accumulate = false;

    cv::Mat blueHistogram;
    cv::Mat redHistogram;
    cv::Mat greenHistogram;
    cv::calcHist(&BGR[0], 1, 0, cv::Mat(), blueHistogram, 1, &histogramSize, &histRange, uniform, accumulate);
    cv::calcHist(&BGR[1], 1, 0, cv::Mat(), greenHistogram, 1, &histogramSize, &histRange, uniform, accumulate);
    cv::calcHist(&BGR[2], 1, 0, cv::Mat(), redHistogram, 1, &histogramSize, &histRange, uniform, accumulate);

    int histWidth = 512;
    int histHeight = 400;
    int binWidth = cvRound((double)histWidth / histogramSize);
    cv::Mat histImage(histHeight, histWidth, CV_8UC3, cv::Scalar(0,0,0));

    cv::normalize(blueHistogram, blueHistogram, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
    cv::normalize(greenHistogram, greenHistogram, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
    cv::normalize(redHistogram, redHistogram, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());

    for(int i = 1; i <= histogramSize; i++){
        line(histImage, cv::Point(binWidth * (i-1), histHeight - cvRound(blueHistogram.at<float>(i-1))),
              cv::Point(binWidth * (i), histHeight - cvRound(blueHistogram.at<float>(i))),
              cv::Scalar(255, 0, 0), 1, 8, 0);
        line(histImage, cv::Point(binWidth * (i-1), histHeight - cvRound(greenHistogram.at<float>(i-1))),
              cv::Point(binWidth * (i), histHeight - cvRound(greenHistogram.at<float>(i))),
              cv::Scalar(0, 255, 0), 1, 8, 0);
        line(histImage, cv::Point(binWidth * (i-1), histHeight - cvRound(redHistogram.at<float>(i-1))),
              cv::Point(binWidth * (i), histHeight - cvRound(redHistogram.at<float>(i))),
              cv::Scalar(0, 0, 255), 1, 8, 0);
    }
	imshow("Histogram of the Picture", histImage);
    cv::waitKey();
    return histImage;
}

cv::Mat normalizeColor(cv::Mat img)
{
    cv::cvtColor(img, img, cv::COLOR_BGR2YCrCb);
    std::vector<cv::Mat> channels;
    cv::split(img, channels);
    cv::equalizeHist(channels[0], channels[0]);
    cv::merge(channels, img);
    cv::cvtColor(img, img, cv::COLOR_YCrCb2BGR);
    return img;
}
