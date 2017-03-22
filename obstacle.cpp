#include "obstacle.h"

Obstacle::Obstacle() : MeleeEnemy()
{
    int random_number = rand() % 2;
    if (random_number == 0)
    {
        setPixmap(QPixmap(":/sprites/boxes2.png"));
        damage_value = 10;
        point_value = 5;
    }
    else if (random_number == 1)
    {
        setPixmap(QPixmap(":/sprites/trash_can.png"));
        damage_value = 40;
        point_value = 20;
    }

}

