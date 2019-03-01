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
    cv::threshold( image, dst, 15, 255, cv::THRESH_BINARY );
}

void thresholdingInv (cv::Mat image, cv::Mat dst)
{
    cv::threshold( image, dst, 210, 255, cv::THRESH_BINARY_INV );
}

cv::Mat createLightPattern(cv::Mat image)
{
    cv::Mat pattern;
    cv::blur(image, pattern, cv::Size(image.cols / 3, image.rows / 3));
    return pattern;
}

void sharpening(cv::Mat image)
{
    cv::Mat kernel = (cv::Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    cv::filter2D(image, image, -1/CV_64F, kernel);
    imshow("Sharpened Photo", image);
}

cv::Mat segmentation(cv::Mat segmentImage)
{
    cv::Mat labels;

    int labelNumber = cv::connectedComponents(segmentImage, labels);
    std::cout << "labels :" << labelNumber << std::endl;

    cv::Mat newImg = cv::Mat::zeros(segmentImage.rows, segmentImage.cols, CV_8UC3);

    for (int i = 1; i < labelNumber; ++i) {
        cv::Mat mask = labels == i;
        newImg.setTo(cv::Scalar(165, 115, 147), mask);
    }
    return newImg;
}
cv::Mat segmentationStats(cv::Mat segmentImage)
{
    cv::Mat labels;
    cv::Mat stats;
    cv::Mat centroids;

    int labelNumber = cv::connectedComponentsWithStats(segmentImage, labels, stats, centroids);
    std::cout << "labels: " << labelNumber << std::endl;

    cv::Mat newImg = cv::Mat::zeros(segmentImage.rows, segmentImage.cols, CV_8UC3);

    std::vector<int> area;

    for (int i = 1; i < labelNumber; ++i) {
        cv::Mat mask = labels == i;
        newImg.setTo(cv::Scalar(165, 115, 147), mask);
        area.push_back(stats.at<int>(i, cv::CC_STAT_AREA));
    }
    int counter;
    std::vector<int> sorted = quickSort(area, 0, area.size()-1, counter, 0);
    for (int j = 0; j < sorted.size(); ++j) {

        for (int i = 0; i < labelNumber; ++i) {
            if(stats.at<int>(i, cv::CC_STAT_AREA) == sorted[j]) {
                std::string nextOne = std::to_string(j + 1);
                cv::putText(newImg, nextOne, cv::Point(centroids.at<cv::Point2d>(i)), cv::FONT_HERSHEY_SIMPLEX, 0.5,
                            cv::Scalar(0), 1, 0, false);
                cv::Vec3i c = sorted[i];
                char areaSize[11];
                double x = centroids.at<double>(i, 0);
                double y = centroids.at<double>(i, 1);
                sprintf(areaSize, "area = %d", area[j]);
                cv::putText(newImg, areaSize, cv::Point(x - 30, y - 40 ), cv::FONT_HERSHEY_SIMPLEX, 0.5,
                                                        cv::Scalar(255, 255, 255), 1, 8, false);
            }
        }
    }
    return newImg;
}

cv::Mat akazeDetection(cv::Mat image)
{
    cv::Mat homography;
    cv::FileStorage fs("akaze.xml", cv::FileStorage::READ);
    fs.getFirstTopLevelNode() >> homography;

    std::vector<cv::KeyPoint> keypoints;
    cv::Ptr<cv::AKAZE> akaze = cv::AKAZE::create();
    akaze->detect(image, keypoints);
    cv::Mat img_keypoints;
    drawKeypoints(image, keypoints, img_keypoints, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);

    std::cout << "Found " << keypoints.size() << " keypoints on the picture." << std::endl;

    return img_keypoints;
}

cv::Mat fastFeatureDetection(cv::Mat image)
{

	sharpening(image);
	cv::Mat homography;
	cv::FileStorage fs("fastFeatureDetector.xml", cv::FileStorage::READ);
	fs.getFirstTopLevelNode() >> homography;

	std::vector<cv::KeyPoint> keypoints;
	
	cv::Ptr<cv::FastFeatureDetector> fastFeatureDetect = cv::FastFeatureDetector::create();
	fastFeatureDetect->detect(image, keypoints);
	cv::Mat img_keypoints;
	drawKeypoints(image, keypoints, img_keypoints, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);

	std::cout << "Found " << keypoints.size() << " keypoints on the picture." << std::endl;

	return img_keypoints;
}