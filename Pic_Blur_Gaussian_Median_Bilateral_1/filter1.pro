#-------------------------------------------------
#
# Project created by QtCreator 2020-09-25T23:09:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = filter1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += D:/Work/Code/Learn/OpenCV01/Qt/opencv-mingw-3.4.5/include\
               D:/Work/Code/Learn/OpenCV01/Qt/opencv-mingw-3.4.5/include/opencv\
               D:/Work/Code/Learn/OpenCV01/Qt/opencv-mingw-3.4.5/include/opencv2

LIBS += -L D:/Work/Code/Learn/OpenCV01/Qt/opencv-mingw-3.4.5/lib/libopencv_*.a
