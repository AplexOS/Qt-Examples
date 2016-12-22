#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fcntl.h>
#include <stdio.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->slider,SIGNAL(valueChanged(int)),this,SLOT(sliderchanged(int)));

    fd = ::open("/sys/class/backlight/pwm-backlight.1/brightness",O_RDWR|O_NONBLOCK);
}

MainWindow::~MainWindow()
{
    delete ui;
    ::close(fd);
}

void MainWindow::sliderchanged(int v)
{
    char buf[20];
    sprintf(buf,"%d",(int)((v/100.0)*248));
    ::write(fd,buf,sizeof(buf));
    qDebug() << (int)((v/100.0)*248) << endl;
}

void MainWindow::moveEvent(QMoveEvent *)
{
    this->move(QPoint(0,0));
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    this->showMaximized();
}

