#include "bullet_enemy.h"

BulletEnemy::BulletEnemy() : Enemy()
{
    setPixmap(QPixmap(":/sprites/Bullet.png"));

    damage_value = 80;
    point_value = 0;
}

void BulletEnemy::move()
{
    setPos(x() - 30, y());
    //Delete it if it goes past the bottom
    if (pos().x() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
