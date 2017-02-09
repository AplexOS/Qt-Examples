#include "backlight.h"
#include "ui_backlight.h"
#include <fcntl.h>
#include <stdio.h>
#include <QDebug>
#include <unistd.h>

Backlight::Backlight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Backlight)
{
    ui->setupUi(this);

    connect(ui->slider,SIGNAL(valueChanged(int)),this,SLOT(sliderchanged(int)));

    fd = ::open("/sys/class/backlight/pwm-backlight/brightness",O_RDWR|O_NONBLOCK);
}

Backlight::~Backlight()
{
    delete ui;
    ::close(fd);
}

void Backlight::sliderchanged(int v)
{
    char buf[20];
    sprintf(buf,"%d",(int)((v/100.0)*248));
    ::write(fd,buf,sizeof(buf));
    qDebug() << (int)((v/100.0)*248) << endl;
}

void Backlight::moveEvent(QMoveEvent *)
{
    this->move(QPoint(0,0));
}

void Backlight::resizeEvent(QResizeEvent *)
{
    this->showMaximized();
}
