#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMainWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainWindow(){
    QString imgPath="test.jpg";
    Mat imgData=imread(imgPath.toLatin1().data());
    cvtColor(imgData,imgData,COLOR_BGR2RGB);
    myImg=imgData;
    myQImg=QImage((const unsigned char*)(imgData.data),imgData.cols,imgData.rows,QImage::Format_RGB888);
    imgShow();
}

void MainWindow::imgShow(){
    ui->viewLabel->setPixmap(QPixmap::fromImage(myQImg.scaled(ui->viewLabel->size(),Qt::KeepAspectRatio)));
}

void MainWindow::imgProc(float ang, float sca){
    Point2f srcMatrix[3];
    Point2f dstMatrix[3];
    Mat imgRot(2,3,CV_32FC1);
    Mat imgSrc=myImg;
    Mat imgDst;
    Point centerPoint=Point(imgSrc.cols/2,imgSrc.rows/2);
    imgRot=getRotationMatrix2D(centerPoint,ang,sca);
    warpAffine(imgSrc,imgDst,imgRot,imgSrc.size());
    myQImg=QImage((const unsigned char*)(imgDst.data),imgDst.cols,imgDst.rows,QImage::Format_RGB888);
    imgShow();
}

void MainWindow::on_rotateHorizontalSlider_sliderMoved(int position){
    imgProc(float(position-360),ui->scaleVerticalSlider->value()/100.0);
}

void MainWindow::on_rotateHorizontalSlider_valueChanged(int value){
    imgProc(float(value-360),ui->scaleVerticalSlider->value()/100.0);
}

void MainWindow::on_scaleVerticalSlider_sliderMoved(int position){
    imgProc(float(ui->rotateHorizontalSilder->value()-360),position/100.0);
}

void MainWindow::on_scaleVerticalSlider_valueChanged(int value){
    imgProc(float(ui->rotateHorizontalSilder->value()-360),value/100.0);
}
