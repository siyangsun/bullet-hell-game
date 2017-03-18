#include "melee_enemy.h"

extern Game *game;

MeleeEnemy::MeleeEnemy() : Enemy()
{



}



void MeleeEnemy::move()
{
    setPos(x(), y() + 10);
    //Delete it if it goes past the bottom
    if (pos().y() > 600)
    {
        scene()->removeItem(this);
        delete this;
    }
}
