#include "widget.h"

#include <QLabel>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{
}

void Widget::makeLabels(int blockSize)
{
    int y;
    int x;
    for (y = 0; y < (this->height() / blockSize); y++) {
        for (x = 0; x < (this->width() / blockSize); x++) {
            QLabel *label = new QLabel(this);
            label->setGeometry(x * blockSize, y * blockSize,
                               blockSize, blockSize);
            label->setText(QString("%1x%2").arg(x).arg(y));
            label->setFrameStyle(QLabel::Box | QLabel::Raised);
            label->setLineWidth(3);
            label->show();
        }
    }
    qDebug() << __func__ << this->size() << "-> max-label(" << x << "x" << y << ") blockSize=" << blockSize;
}
