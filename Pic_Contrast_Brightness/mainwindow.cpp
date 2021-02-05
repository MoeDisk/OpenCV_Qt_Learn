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
    QString imgPath="D:/test.jpg";
    Mat imgData=imread(imgPath.toLatin1().data());
    cvtColor(imgData,imgData,COLOR_BGR2RGB);
    myImg=imgData;
    myQImg=QImage((const unsigned char*)(imgData.data),imgData.cols,imgData.rows,QImage::Format_RGB888);
    imgShow();
}

void MainWindow::imgShow(){
    ui->view_Label->setPixmap(QPixmap::fromImage(myQImg.scaled(ui->view_Label->size(),Qt::KeepAspectRatio)));
}

void MainWindow::imgProc(float con,int bri){
    Mat imgSrc=myImg;
    Mat imgDst=Mat::zeros(imgSrc.size(),imgSrc.type());
    imgSrc.convertTo(imgDst,-1,con,bri);
    myQImg=QImage((const unsigned char*)(imgDst.data),imgDst.cols,imgDst.rows,QImage::Format_RGB888);
    imgShow();
}

void MainWindow::on_contrastVerticalSlider_sliderMoved(int position){
    imgProc(position/33.3,0);
}

void MainWindow::on_contrastVerticalSlider_valueChanged(int value){
    imgProc(value/33.3,0);
}

void MainWindow::on_brightnessVerticalSlider_sliderMoved(int position){
    imgProc(1.0,position);
}

void MainWindow::on_brightnessVerticalSlider_valueChanged(int value){
    imgProc(1.0,value);
}
