#include "melee_enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

//MeleeEnemy::MeleeEnemy() : Enemy() {}
/*
MeleeEnemy::MeleeEnemy()
{
    int random_number = rand() % 700;
    setPos(random_number, 0);

    setRect(0, 0, 50, 50);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}
*/

MeleeEnemy::MeleeEnemy()
{
    int random_number = rand() % 700;
    setPos(random_number, -100);

    setRect(0, 0, 50, 50);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void MeleeEnemy::move()
{
    setPos(x(), y() + 5);
    //Delete it if it goes past the bottom
    if (pos().y() > 600)
    {
        scene()->removeItem(this);
        delete this;
    }

}
