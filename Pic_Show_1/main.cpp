#include <QCoreApplication>
#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mat img = cv::imread("D:/test.jpg");
    imshow("Test", img);
    waitKey(0);

    destroyAllWindows();

    return a.exec();

}
