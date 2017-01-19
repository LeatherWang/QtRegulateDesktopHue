#ifndef DETECTHUE
#define DETECTHUE
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <QDebug>

using namespace std;
using namespace cv;

class DetectHue{
private:

public:
    DetectHue(){}
    int calculateAvrHue(Mat &image);

    //查表法减色
    void colorReduce0(Mat &image,int div=16)//针对灰度图像
    {
        Mat lookup(1,256,CV_8U);
        for(int i=0; i<256; i++)
            lookup.at<uchar>(i) = i/div * div + div/2;
        LUT(image,lookup,image);
    }

    //图像运算符减色
    void colorReduce1(cv::Mat &image, int div=64)
    {
          int n= static_cast<int>(log(static_cast<double>(div))/log(2.0) + 0.5);
          uchar mask= 0xFF<<n; // e.g. for div=16, mask= 0xF
          image=(image&cv::Scalar(mask,mask,mask))+cv::Scalar(div/2,div/2,div/2);
    }
};
#endif // DETECTHUE

