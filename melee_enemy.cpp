#include "melee_enemy.h"

extern Game *game;

MeleeEnemy::MeleeEnemy() : Enemy()
{



}



void MeleeEnemy::move()
{
    setPos(x() - 10, y());
}
