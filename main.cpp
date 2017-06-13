#include "mainwindow.h"
#include <QtGui/QApplication>
#include <QApplication>

#include <QTextCodec>
#include "./inputpanel/myinputpanel.h"
#include "./inputpanel/myinputpanelcontext.h"
#include "./burncpu/parser.h"
/*
Parser myParser;

class MyFirstThread : public QThread
{
private:
    void run()
    {
//        myParser.runParser();
        QTimer *testTimer = new QTimer(this);
        //将定时器超时信号与槽(功能函数)联系起来
        connect(testTimer,SIGNAL(timeout()), &myParser, SLOT(runParser()) );
        //开始运行定时器，定时时间间隔为1000ms
        testTimer->start(1000);
        qDebug() << "my thread";
    }
};
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyInputPanelContext *ic = new MyInputPanelContext;
    a.setInputContext(ic);//将输入上下文与应用程序关联

    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
    MainWindow w;

    w.setWindowFlags(w.windowFlags()& ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint);
    w.showMaximized();

//    MyFirstThread t1;
//    t1.start();
/*
        QTimer *testTimer = new QTimer(&w);
        //将定时器超时信号与槽(功能函数)联系起来
        QObject::connect(testTimer,SIGNAL(timeout()), &myParser, SLOT(runParser()) );
        //开始运行定时器，定时时间间隔为1000ms
        testTimer->start(1000);
        qDebug() << "my thread";

    QObject::connect(&myParser, SIGNAL(parserSignal(int)), w.burnCpu, SLOT(usageSlot(int)));
*/

    return a.exec();
}
