#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>


Enemy::Enemy()
{
    int random_number = rand() % 700;
    setPos(random_number, 0);

    setRect(0, 0, 50, 50);
    QTimer * timer = new QTimer();
    //connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{

}

