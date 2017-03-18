#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "melee_enemy.h"
#include "game.h"

extern Game *game;

Bullet::Bullet()
{
    setPixmap(QPixmap(":/sprites/Bullet.png"));
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}


void Bullet::move()
{
    setPos(x(), y() - 20);
    if (pos().y() + boundingRect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

