#include <opencv2/opencv.hpp>
#include <iostream>

constexpr auto Pi = 3.1415926;;

using namespace cv;
using namespace std;

int main()
{
	/*
	//Canny
	VideoCapture cap;
	cap.open(0);

	while (1)
	{
		Mat frame;
		cap.read(frame);

		Mat grand_x,grand_y;
		Sobel(frame,grand_x, CV_16SC1,1,0);
		Sobel(frame,grand_y, CV_16SC1,0,1);

		Mat canny_img,can_img;
		Canny(frame, canny_img, 20, 60);
		Canny(grand_x, grand_y,can_img, 20, 60);

		imshow("res", canny_img);
		imshow("res2", can_img);
		waitKey(30);
	}
	*/
	
	Mat srcMat = imread("lena.jpg"); 
	Mat dst;
	////////////////////////////////////Á·Ï°2 +Ë¼¿¼
	double angle = -10.0;
	double scale = 1 + 10*sin(angle/(180*Pi));
	Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);

	Mat M;
	M = getRotationMatrix2D(center, angle, scale);
	warpAffine(srcMat, dst, M, srcMat.size());


	imshow("src", srcMat);
	imshow("dst", dst);
	waitKey(0);
	


	/*///////////////////////////////Á·Ï°3
	Point2f src_pt[] = { Point2f(200,200),Point2f(250,200),Point2f(200,100) };
	Point2f dst_pt[] = { Point2f(300,100),Point2f(300,50),Point2f(200,100) };

	Mat M2;
	M2 = getAffineTransform(src_pt, dst_pt);
	warpAffine(srcMat, dst, M2, srcMat.size());

	imshow("src", srcMat);
	imshow("dst", dst);
	waitKey(0);
	*/

	/*////////////////////////////////Á·Ï°4
	Point2f pts1[] = { Point2f(150,150),Point2f(150,300),Point2f(350,300),Point2f(350,150) };
	Point2f pts2[] = { Point2f(200,150),Point2f(200,300),Point2f(340,270),Point2f(340,180) };

	Mat M3 = getPerspectiveTransform(pts1, pts2);
	warpPerspective(srcMat, dst, M3, srcMat.size());
	imshow("src", srcMat);
	imshow("dst", dst);
	waitKey(0);
	*/

	//////////////////////Á·Ï°5
	/*
	Mat src = imread("lena_rot.jpg");
	RotatedRect r_rect;
	Rect rect;
	Mat gray, thr;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	threshold(gray, thr, 250, 255, THRESH_BINARY_INV);

	Point2f center2(src.cols*0.5, src.rows*0.5);
	vector<vector<Point>> con;
	findContours(thr, con, RETR_LIST, CHAIN_APPROX_SIMPLE);

	r_rect = minAreaRect(con[0]);
	
	vector<Point> approx;

	if (r_rect.angle < -45.0)
	{
		r_rect.angle += 90.0;
	}

	double scale = src.rows / r_rect.size.width;
	Mat M4 = getRotationMatrix2D(center2, r_rect.angle, scale);
	
	warpAffine(src, dst, M4, src.size());
	

	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
	*/
	return 0;
}