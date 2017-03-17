#include "bullet_enemy.h"
#include <QGraphicsScene>

BulletEnemy::BulletEnemy() : Enemy()
{
    setRect(0, 0, 8, 20);

    damage_value = 20;
    point_value = 0;
}

void BulletEnemy::move()
{
    setPos(x(), y() + 15);
    //Delete it if it goes past the bottom
    if (pos().y() > 600)
    {
        scene()->removeItem(this);
        delete this;
    }
}
