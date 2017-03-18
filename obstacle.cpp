#include "obstacle.h"

Obstacle::Obstacle() : MeleeEnemy()
{
    int random_number = rand() % 2;
    if (random_number == 0)
    {
        setPixmap(QPixmap(":/sprites/Boxes.png"));
        damage_value = 10;
        point_value = 5;
    }
    else if (random_number == 1)
    {
        setPixmap(QPixmap(":/sprites/Roadblock1.png"));
        damage_value = 40;
        point_value = 20;
    }

}

