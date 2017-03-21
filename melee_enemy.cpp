#include "melee_enemy.h"

extern Game *game;

MeleeEnemy::MeleeEnemy() : Enemy()
{



}



void MeleeEnemy::move()
{
    setPos(x() - 10, y());
    //Delete it if it goes past the bottom
    if (pos().x() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
