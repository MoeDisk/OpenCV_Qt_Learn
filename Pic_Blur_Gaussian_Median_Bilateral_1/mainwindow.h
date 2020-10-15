#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opencv2/opencv.hpp"
#include <QFileDialog>
#include <QScreen>

using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initMainWindow();
    void imgProc(int kernel);
    void imgShow();

private slots:
    void on_kernelVerticalSlider_sliderMoved(int position);
    void on_kernelVerticalSlider_valueChanged(int value);
    void on_saveAsPushButton_clicked();

private:
    Ui::MainWindow *ui;
    Mat myImg;
    QImage myBlurQImg;
    QImage myGaussianQImg;
    QImage myMedianQImg;
    QImage myBilateralQImg;
};

#endif // MAINWINDOW_H
