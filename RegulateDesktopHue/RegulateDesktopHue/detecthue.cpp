
#include "detecthue.h"

int DetectHue::calculateAvrHue(Mat &image)
{
    Mat hsv;
    cv::cvtColor(image, hsv, CV_BGR2HSV);

    ulong VTotal = 0;
    int nl = image.rows;
    int nc = image.cols;
    for(int j=0; j<nl;j++)
    {
        for(int i=0;i<nc;i++)
        {
           VTotal +=hsv.at<cv::Vec3b>(j,i)[2];
        }
    }
    return (uchar)(VTotal/image.total());
}
