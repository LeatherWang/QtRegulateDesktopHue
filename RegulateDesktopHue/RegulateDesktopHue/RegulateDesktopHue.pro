#-------------------------------------------------
#
# Project created by QtCreator 2017-01-09T09:21:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RegulateDesktopHue
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    detecthue.cpp

HEADERS  += mainwindow.h \
    desktopparameter.h \
    detecthue.h

FORMS    += mainwindow.ui

LIBS += -lGdi32

INCLUDEPATH+=D:\QTOPENCV\include\opencv\
                    D:\QTOPENCV\include\opencv2\
                    D:\QTOPENCV\include
LIBS+=D:\QTOPENCV\lib\libopencv_calib3d249.dll.a\
        D:\QTOPENCV\lib\libopencv_contrib249.dll.a\
        D:\QTOPENCV\lib\libopencv_core249.dll.a\
        D:\QTOPENCV\lib\libopencv_features2d249.dll.a\
        D:\QTOPENCV\lib\libopencv_flann249.dll.a\
        D:\QTOPENCV\lib\libopencv_gpu249.dll.a\
        D:\QTOPENCV\lib\libopencv_highgui249.dll.a\
        D:\QTOPENCV\lib\libopencv_imgproc249.dll.a\
        D:\QTOPENCV\lib\libopencv_legacy249.dll.a\
        D:\QTOPENCV\lib\libopencv_ml249.dll.a\
        D:\QTOPENCV\lib\libopencv_objdetect249.dll.a\
        D:\QTOPENCV\lib\libopencv_video249.dll.a
