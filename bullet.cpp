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
    setPixmap(QPixmap(":/sprites/bullet_horizontal.png"));
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}


void Bullet::move()
{
    setPos(x() + 25, y());
    if (pos().x() + boundingRect().width() > 800)
    {
        scene()->removeItem(this);
        delete this;
    }
}

