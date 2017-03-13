#ifndef MELEE_ENEMY_H
#define MELEE_ENEMY_H

#include "enemy.h"
#include <QObject>
#include <QTimer>


class MeleeEnemy : public Enemy
{
    Q_OBJECT
public:
    MeleeEnemy();
public slots:
    void move();
};

#endif // MELEE_ENEMY_H
