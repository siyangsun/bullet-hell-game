#include "melee_enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "game.h"
#include <QList>
#include "bullet.h"

extern Game *game;

MeleeEnemy::MeleeEnemy() : Enemy()
{
    setRect(0, 0, 60, 60);

    damage_value = 40;
    point_value = 10;
}



void MeleeEnemy::move()
{
    int random_number = rand() % 4;
    setPos(x() + 2 - random_number, y() + 5);
    //Delete it if it goes past the bottom
    if (pos().y() > 600)
    {
        scene()->removeItem(this);
        delete this;
    }

}
