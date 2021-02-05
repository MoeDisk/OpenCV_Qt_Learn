#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opencv2/opencv.hpp"

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
    void imgProc(float contrast,int brightness);
    void imgShow();

private slots:
    void on_contrastVerticalSlider_sliderMoved(int position);
    void on_contrastVerticalSlider_valueChanged(int value);
    void on_brightnessVerticalSlider_sliderMoved(int position);
    void on_brightnessVerticalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    Mat myImg;
    QImage myQImg;
};

#endif // MAINWINDOW_H
