#include "myrect.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "bullet.h"

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right) {
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space) {
        //create a bullet
        Bullet * bullet = new Bullet();
        scene()->addItem(bullet);
        //qDebug() << "bullet created";
    }
}
