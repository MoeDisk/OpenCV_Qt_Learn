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
    void imgProc(float angle,float scale);
    void imgShow();

private slots:
    void on_rotateHorizontalSlider_sliderMoved(int position);
    void on_rotateHorizontalSlider_valueChanged(int value);
    void on_scaleVerticalSlider_sliderMoved(int position);
    void on_scaleVerticalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    Mat myImg;
    QImage myQImg;
};

#endif // MAINWINDOW_H
