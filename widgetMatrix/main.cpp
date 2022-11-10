#include "widget.h"

#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget *w = new Widget();
    w->setGeometry(0, 0, 1024, 600); // set fullscreen size of your LCD for Test
    w->showFullScreen();

    QTimer *timer = new QTimer();
    timer->setInterval(0);
    timer->setSingleShot(true);
    QObject::connect(timer, &QTimer::timeout,
                     [=](){
        w->makeLabels(128); // blocksize
    });
    timer->start();

    return a.exec();
}
