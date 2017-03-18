#ifndef BIKER_ENEMY_H
#define BIKER_ENEMY_H

#include "enemy.h"


class BikerEnemy : public Enemy
{
    Q_OBJECT
public:
    BikerEnemy();
public slots:
    void move();
};

#endif // BIKER_ENEMY_H
