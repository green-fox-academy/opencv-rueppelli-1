#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <iostream>
#include <leptonica/allheaders.h>
#include <tesseract/baseapi.h>

#include "detect_circles.h"
#include "database_handler.h"
#include "image_manipulation.h"
#include "sorting.h"
#include "histogram.h"

int main(int argc, char* argv[])
{
	// 1st try.

	cv::Mat practisePicture = cv::imread(argv[3], cv::IMREAD_UNCHANGED);

	cvtColor(practisePicture, practisePicture, cv::COLOR_BGR2RGBA);

	//detectCircle(practisePicture);
	std::string outText;

	//cvtColor(practisePicture, practisePicture, cv::COLOR_GRAY2BGR);
	tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

	if (api->Init(NULL, "eng")) {
		fprintf(stderr, "Could not initialize tesseract.\n");
		exit(1);
	}

	api->SetImage(practisePicture.data, practisePicture.cols, practisePicture.rows, 4, 4 * practisePicture.cols);
	Pix *image = pixCreate(practisePicture.size().width, practisePicture.size().height, 8);


	cvtColor(practisePicture, practisePicture, cv::COLOR_BGR2GRAY);
	//api->SetImage(image);

	outText = api->GetUTF8Text();
	std::cout << "Speedlimit: " << outText << std::endl;

	api->End();
	pixDestroy(&image);


	// 2nd try.
	/*
	std::string outText;

	tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();

	ocr->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
	ocr->SetPageSegMode(tesseract::PSM_AUTO);

	cv::Mat myPicture = cv::imread(argv[3], cv::IMREAD_UNCHANGED);
	//detectCircle(myPicture);
	//cvtColor(myPicture, myPicture, cv::COLOR_GRAY2BGR);
	ocr->SetImage(myPicture.data, myPicture.cols, myPicture.rows, 3, myPicture.step);
	outText = ocr->GetUTF8Text();

	std::cout << outText << std::endl;

	cv::waitKey(0); */
    return 0;
}
