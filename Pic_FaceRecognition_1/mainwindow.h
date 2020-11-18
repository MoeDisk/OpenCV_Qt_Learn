#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opencv2/opencv.hpp"
#include <vector>
#include <QString>
#include <QMessageBox>

using namespace std;
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
    void imgProc();
    void imgShow();

private slots:
    void on_detectPushButton_clicked();

private:
    Ui::MainWindow *ui;
    Mat myImg;
    QImage myQImg;
};

#endif // MAINWINDOW_H
