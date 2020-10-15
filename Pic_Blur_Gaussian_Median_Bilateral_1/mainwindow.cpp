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
    QString imgPath=QFileDialog::getOpenFileName();
    Mat imgData=imread(imgPath.toLatin1().data());
    cvtColor(imgData,imgData,COLOR_BGR2RGB);
    myImg=imgData;
    myBlurQImg=QImage((const unsigned char*)(imgData.data),imgData.cols,imgData.rows,QImage::Format_RGB888);
    myGaussianQImg=myBlurQImg;
    myMedianQImg=myBlurQImg;
    myBilateralQImg=myBlurQImg;
    imgShow();
}

void MainWindow::imgShow(){
    ui->blurViewLabel->setPixmap(QPixmap::fromImage(myBlurQImg.scaled(ui->blurViewLabel->size(),Qt::KeepAspectRatio)));
    ui->gaussianViewLabel->setPixmap(QPixmap::fromImage(myGaussianQImg.scaled(ui->gaussianViewLabel->size(),Qt::KeepAspectRatio)));
    ui->medianViewLabel->setPixmap(QPixmap::fromImage(myMedianQImg.scaled(ui->medianViewLabel->size(),Qt::KeepAspectRatio)));
    ui->bilateralViewLabel->setPixmap(QPixmap::fromImage(myBilateralQImg.scaled(ui->bilateralViewLabel->size(),Qt::KeepAspectRatio)));
}

void MainWindow::imgProc(int ker){
    Mat imgSrc=myImg;
    Mat imgDst1=imgSrc.clone();
    for(int i=1;i<ker;i+=2) blur(imgSrc,imgDst1,Size(i,i),Point(-1,-1));
    myBlurQImg=QImage((const unsigned char*)(imgDst1.data),imgDst1.cols,imgDst1.rows,QImage::Format_RGB888);
    Mat imgDst2=imgSrc.clone();
    for(int i=1;i<ker;i+=2) GaussianBlur(imgSrc,imgDst2,Size(i,i),0,0);
    myGaussianQImg=QImage((const unsigned char*)(imgDst2.data),imgDst2.cols,imgDst2.rows,QImage::Format_RGB888);
    Mat imgDst3=imgSrc.clone();
    for(int i=1;i<ker;i+=2) medianBlur(imgSrc,imgDst3,i);
    myMedianQImg=QImage((const unsigned char*)(imgDst3.data),imgDst3.cols,imgDst3.rows,QImage::Format_RGB888);
    Mat imgDst4=imgSrc.clone();
    for(int i=1;i<ker;i+=2) bilateralFilter(imgSrc,imgDst4,i,i*2,i/2);
    myBilateralQImg=QImage((const unsigned char*)(imgDst4.data),imgDst4.cols,imgDst4.rows,QImage::Format_RGB888);
    imgShow();
}

void MainWindow::on_kernelVerticalSlider_sliderMoved(int position){
    imgProc(position);
}

void MainWindow::on_kernelVerticalSlider_valueChanged(int value){
    imgProc(value);
}

void MainWindow::on_saveAsPushButton_clicked(){
    QString filename=QFileDialog::getSaveFileName(this, tr("保存图片"),"ladydiver_processed",tr("图片文件(*.png *jpg *.jpeg *.bmp"));
    QScreen *screen=QGuiApplication::primaryScreen();
    if(ui->blurRadioButton->isChecked()) screen->grabWindow(ui->medianViewLabel->winId()).save(filename);
    if(ui->gaussianRadioButton->isChecked()) screen->grabWindow(ui->gaussianViewLabel->winId()).save(filename);
    if(ui->medianRadioButton->isChecked()) screen->grabWindow(ui->medianViewLabel->winId()).save(filename);
    if(ui->bilateralRadioButton->isChecked()) screen->grabWindow(ui->bilateralViewLabel->winId()).save(filename);
}
