#include "bullet_enemy.h"

BulletEnemy::BulletEnemy() : Enemy()
{
    setPixmap(QPixmap(":/sprites/Bullet.png"));

    damage_value = 80;
    point_value = 0;
}

void BulletEnemy::move()
{
    setPos(x(), y() + 30);
    //Delete it if it goes past the bottom
    if (pos().y() > 600)
    {
        scene()->removeItem(this);
        delete this;
    }
}
