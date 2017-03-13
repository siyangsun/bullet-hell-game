#ifndef BULLET_ENEMY_H
#define BULLET_ENEMY_H

#include "enemy.h"


class BulletEnemy : public Enemy
{
public:
    BulletEnemy();
public slots:
    void move();
};

#endif // BULLET_ENEMY_H
