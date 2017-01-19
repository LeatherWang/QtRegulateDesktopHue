#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <windows.h>
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    desk1 =new DesktopDetector(0);
    desk1->GetScreenInfo();

    ui->label_Ratio->setText(QString::number(desk1->GetScreenRadioX())+"*"+QString::number(desk1->GetScreenRadioY()));
    ui->label_ScreenCount->setText(QString::number(desk1->GetScreenCount()));

    fileName = "./pic.jpg";

    mytimer = new QTimer(this);
    connect(mytimer,SIGNAL(timeout()),this,SLOT(on_pushButton_3_clicked()));
    mytimer->setInterval(30000);
    mytimer->start();
//    qDebug()<<desk1.SetGamma(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Mat image = imread(fileName.toStdString(),1);
    if(!image.data)
        return;

    DetectHue detecthue;
    namedWindow("原图");
    //detecthue.colorReduce1(image,64);
    imshow("原图",image);

    double duration = (double)(getTickCount());
    qDebug()<<detecthue.calculateAvrHue(image);
    duration = (double)(((getTickCount()) - duration)/getTickFrequency());
    qDebug() <<"运行时间" << duration<< 's';

    while(waitKey(0) != ' ');
    destroyWindow("原图");
}

void MainWindow::on_pushButton_2_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files (*.png *.jpg *.bmp)"));
}

#define LIMIT( x,min,max )  ( (x) < (min)  ? (min) : ( (x) > (max) ? (max) : (x) ) )
void MainWindow::on_pushButton_3_clicked()
{
    if(!capture.isOpened())
        capture.open(0);
    uint gammaSum=0;
    for(int i=10;i>0;i--)
    {
        Mat frame;
        capture>>frame;
        if(!frame.data)
            return;
        //detecthue.colorReduce1(image,64);
        DetectHue detecthue;
        gammaSum += detecthue.calculateAvrHue(frame);
        waitKey(20);
    }

    uchar gamma = 100 - gammaSum/120;//10*12
//    qDebug()<<gamma;
    desk1->SetGamma(LIMIT(gamma,80,100));
    capture.release();
}
