#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "desktopparameter.h"
#include "detecthue.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <QMouseEvent>
#include <QTimer>

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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QString fileName;
    VideoCapture capture;
    DesktopDetector *desk1;
    QTimer *mytimer;
};

#endif // MAINWINDOW_H
