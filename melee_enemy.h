#ifndef MELEE_ENEMY_H
#define MELEE_ENEMY_H

#include "enemy.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>


class MeleeEnemy : public Enemy
{
    Q_OBJECT
public:
    MeleeEnemy();
public slots:
    virtual void move();
};

#endif // MELEE_ENEMY_H
