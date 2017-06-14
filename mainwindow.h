#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGroupBox>

#include "./info/info.h"
#include "./led/led.h"
#include "./gpio/myGpio.h"
#include "./buzzer/buzzer.h"
#include "./backlight/backlight.h"
#include "./eeprom/eeprom.h"
#include "./network/network.h"
#include "./ping/ping.h"
#include "./usb/usb.h"
#include "./SD/sd.h"
//#include "./OnOff/onoff.h"
#include "./uart/uart.h"
#include "./watchdog/watchdog.h"
#include "./can/canTest.h"
#include "./audio/audio.h"
#include "./rtc/rtcTest.h"
//#include "./burncpu/burnCpu.h"
#include "./version/version.h"
#include "./ifconfig/dpifconfig.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTabWidget *tabWidget;
    void updateSizes(int index);

public:

    Info *info;

    Led *led;

    MyGpio *gpio;

    Buzzer *buzzer;

    Backlight *backlight;

    Eeprom *eeprom;

    Network *network;

    Ping *ping;

    RtcTest *rtc;

    Usb *usb;

    Sd *sd;

//    OnOff *onoff;

//    BurnCpu *burnCpu;

    Uart *uart;

    Watchdog *watchdog;

    CanTest *can;

    Audio *audio;

    dpifconfig *aplex_ifconfig;

    version *version1;

private slots:
//    void on_tabWidget_currentChanged(QWidget *arg1);

//    void on_tabWidget_currentChanged(int index);

//    void on_tabWidget_selected(const QString &arg1);

//    void on_tabWidget_tabCloseRequested(int index);

//    void on_tabWidget_destroyed();

//    void on_tabWidget_destroyed(QObject *arg1);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
