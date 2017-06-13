#include "backlight.h"
#include "ui_backlight.h"
#include <fcntl.h>
#include <stdio.h>
//#include <qpushbutton.h>
#include <sys/types.h>
#include <unistd.h>
#include <QDebug>
Backlight::Backlight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Backlight)
{
    ui->setupUi(this);
    /* use slider to control */
    connect(ui->slider,SIGNAL(valueChanged(int)),this,SLOT(sliderchanged(int)));

    fd = ::open("/sys/class/backlight/pwm-backlight.0/brightness",O_RDWR|O_NONBLOCK);

    char buf[4];
    memset(buf, 0, sizeof(buf));
    ::read(fd, buf, 4);
    ui->slider->setValue(atoi(buf) * 100 / 248);
}

Backlight::~Backlight( )
{
    delete ui;
    ::close(fd);
}

void Backlight::sliderchanged(int v)
{
    char buf[20];
    memset(buf, 0, sizeof(buf));
    sprintf(buf,"%d",(int)((v * 248 / 100)));
    ::write(fd,buf,strlen(buf));
    system("cat /sys/class/backlight/pwm-backlight.0/brightness > /etc/brightness");
    system("sync");
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

