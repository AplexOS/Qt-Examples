#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include "buzzer.h"
#include "ui_buzzer.h"
#include <QMessageBox>

#define PWM_IOCTL_SET_FREQ	1
#define PWM_IOCTL_STOP		0

Buzzer::Buzzer(QWidget *parent) :
	QWidget(parent),
    ui(new Ui::Buzzer)
{
    //int pd;
    //char buf[32];

    /*
	pd = open("/proc/boardname", O_RDONLY);

    if (read(pd, buf, 32) < 0){
        perror("read error");
		exit(1);
	}
    if (strncmp(buf,"OK335xD",7) == 0) {
        QMessageBox::about(this,"error","this board doesn't have a buzzer");
		exit(1);
	}

    ::close(pd);
    */

    ui->setupUi(this);

    fd = open("/dev/buzzer", O_RDWR);
    if (fd < 0) {
        perror("open buzzer device");
        exit(1);
    }

    set_buzzer_freq(0);
}

Buzzer::~Buzzer()
{
    ioctl(fd, PWM_IOCTL_STOP);
	delete ui;
    ::close(fd);
}

void Buzzer::set_buzzer_freq(int freq)
{
    int ret = ioctl(fd, PWM_IOCTL_SET_FREQ, freq);
    if(ret < 0){
        perror("set the frequency of the buzzer");
        exit(1);
    }
}

void Buzzer::on_slider_valueChanged(int value)
{
    QString nextState = ui->pushButton->text();
    if (nextState == "STOP") {
        set_buzzer_freq(value);
    }
    ui->spinBox->setValue(value);
}

void Buzzer::on_spinBox_valueChanged(int value)
{
    QString state = ui->pushButton->text();
    if (state == "STOP") {
        set_buzzer_freq(value);
    }
    ui->slider->setValue(value);
}

void Buzzer::moveEvent(QMoveEvent *)
{
    this->move(QPoint(0,0));
}

void Buzzer::resizeEvent(QResizeEvent *)
{
    this->showMaximized();
}

void Buzzer::on_pushButton_clicked()
{
    int freq;
    QString state = ui->pushButton->text();
    if (state == "START") {
        ui->pushButton->setText("STOP");
        freq = ui->slider->value();
        set_buzzer_freq(freq);
    } else if (state == "STOP") {
        ui->pushButton->setText("START");
        set_buzzer_freq(0);
    }
}
