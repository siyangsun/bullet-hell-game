#include "biker_enemy.h"
#include <stdlib.h>


BikerEnemy::BikerEnemy() : Enemy()
{
    int random_number = rand() % 2;
    if (random_number == 0)
    {
        setPixmap(QPixmap(":/sprites/motorcycle_enemy2.png"));
        damage_value = 40;
        point_value = 50;
    }
    else if (random_number == 1)
    {
        setPixmap(QPixmap(":/sprites/motorcycle_knife_enemy2.png"));
        damage_value = 65;
        point_value = 70;
    }
}

void BikerEnemy::move()
//the biker enemies move semi-randomly
{
    int random_number = rand() % 6;
    setPos(x() - 18, y() + 3 - random_number);
}
