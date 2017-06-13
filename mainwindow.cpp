#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QGroupBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    info = new Info();
    ui->tabWidget->addTab(info, "info");

    led = new Led();
    ui->tabWidget->addTab(led, "led");

    gpio = new MyGpio();
    ui->tabWidget->addTab(gpio, "gpio");

    buzzer = new Buzzer();
    ui->tabWidget->addTab(buzzer, "buzzer");

    backlight = new Backlight();
    ui->tabWidget->addTab(backlight, "backlight");

    eeprom = new Eeprom();
    ui->tabWidget->addTab(eeprom, "eeprom");

    network= new Network();
    ui->tabWidget->addTab(network, "network");

    aplex_ifconfig = new dpifconfig();
    ui->tabWidget->addTab(aplex_ifconfig, "ifconfig");

    ping= new Ping();
    ui->tabWidget->addTab(ping, "ping");

    rtc = new RtcTest();
    ui->tabWidget->addTab(rtc, "rtc");

    usb = new Usb();
    ui->tabWidget->addTab(usb, "usb");

    //sd = new Sd();
    //ui->tabWidget->addTab(sd, "SD");
/*
    onoff = new OnOff();
    ui->tabWidget->addTab(onoff, "OnOff");
    if (access("/on-off-file", F_OK) == 0) {
        ui->tabWidget->setCurrentWidget(onoff);
    }
*/
//    burnCpu = new BurnCpu();
//    ui->tabWidget->addTab(burnCpu, "burnCpu");

    uart= new Uart();
    ui->tabWidget->addTab(uart, "uart");

//    watchdog = new Watchdog();
//    ui->tabWidget->addTab(watchdog, "watchdog");

    can = new CanTest();
    ui->tabWidget->addTab(can, "can");

    //audio= new Audio();
    //ui->tabWidget->addTab(audio, "audio");

    //version1 = new version();
    //ui->tabWidget->addTab(version1, "version");



}

MainWindow::~MainWindow()
{
    delete led;

    delete buzzer;

    delete backlight;

    delete eeprom;

    delete network;

    delete ping;

    delete rtc;

    delete usb;

    //delete sd;

//    delete onoff;

    delete uart;

    delete watchdog;

    delete can;

    //delete audio;

    delete version1;

    delete ui;
}

/*
void MainWindow::on_tabWidget_currentChanged(QWidget *arg1)
{
    printf("currentChanged\n");
}

//void MainWindow::on_tabWidget_currentChanged(int index)
//{
//    printf("currentChanged, index: %d\n", index);
//}

void MainWindow::on_tabWidget_selected(const QString &arg1)
{
//    printf("widget select, %s\n", qPrintable(arg1));
    printf("widget select\n");
}
//close
void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    printf("currentChanged, close\n");
}

void MainWindow::on_tabWidget_destroyed()
{
    printf("destory\n");

}

void MainWindow::on_tabWidget_destroyed(QObject *arg1)
{
    printf("destory\n");
}
*/
