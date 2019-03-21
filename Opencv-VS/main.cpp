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
	std::string outText;
	cv::Mat myPicture = cv::imread(argv[3], cv::IMREAD_COLOR);
	
	cv::Mat a = detectCircle(myPicture);
	cv::cvtColor(a, a, 8);

	tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();

	ocr->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
	ocr->SetPageSegMode(tesseract::PSM_AUTO);

	ocr->SetImage(a.data, a.cols, a.rows, 3, a.step);
	outText = ocr->GetUTF8Text();

	std::cout << "Text: " << outText << std::endl;

	cv::waitKey(0); 

	// 2nd try.
	/*
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
	*/

    return 0;
}
