#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T17:31:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    led/led.cpp \
    buzzer/buzzer.cpp \
    inputpanel/myinputpanelcontext.cpp \
    inputpanel/myinputpanel.cpp \
    ping/ping.cpp \
    usb/usb.cpp \
    SD/sd.cpp \
    uart/uart.cpp \
    watchdog/watchdog.cpp \
    can/thread.cpp \
    can/canTest.cpp \
    audio/audio.cpp \
    backlight/backlight.cpp \
    rtc/rtcTest.cpp \
    info/info.cpp \
    burncpu/parser.cpp \
    burncpu/burnCpu.cpp \
    gpio/myGpio.cpp \
    eeprom/i2c.cpp \
    eeprom/eeprom.cpp \
    SD/mountthread.cpp \
    qipaddressedit.cpp \
    qipaddressedititem.cpp \
    interface.cpp \
    version.cpp \
    spi/spi.cpp

HEADERS  += mainwindow.h \
    led.h \
    led/led.h \
    buzzer/buzzer.h \
    inputpanel/myinputpanelcontext.h \
    inputpanel/myinputpanel.h \
    ping/ping.h \
    usb/usb.h \
    SD/sd.h \
    uart/uart.h \
    watchdog/watchdog.h \
    can/thread.h \
    can/canTest.h \
    audio/audio.h \
    backlight/backlight.h \
    rtc/rtcTest.h \
    info/info.h \
    burncpu/parser.h \
    burncpu/burnCpu.h \
    gpio/myGpio.h \
    eeprom/i2c.h \
    eeprom/eeprom.h \
    SD/mountthread.h \
    qipaddressedit.h \
    qipaddressedititem.h \
    interface.h \
    version.h \
    spi/spi.h

FORMS    += mainwindow.ui \
    led/led.ui \
    buzzer/buzzer.ui \
    inputpanel/myinputpanelform.ui \
    ping/ping.ui \
    usb/usb.ui \
    SD/sd.ui \
    uart/uart.ui \
    watchdog/watchdog.ui \
    can/canTest.ui \
    audio/audio.ui \
    backlight/backlight.ui \
    rtc/rtcTest.ui \
    info/info.ui \
    burncpu/burnCpu.ui \
    gpio/myGpio.ui \
    eeprom/eeprom.ui \
    version.ui \
    spi/spi.ui

OTHER_FILES +=
