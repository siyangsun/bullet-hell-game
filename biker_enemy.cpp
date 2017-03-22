#include "biker_enemy.h"


BikerEnemy::BikerEnemy() : Enemy()
{
    int random_number = rand() % 2;
    if (random_number == 0)
    {
        setPixmap(QPixmap(":/sprites/motorcycle_enemy2.png"));
        damage_value = 30;
        point_value = 50;
    }
    else if (random_number == 1)
    {
        setPixmap(QPixmap(":/sprites/motorcycle_knife_enemy2.png"));
        damage_value = 45;
        point_value = 70;
    }
}

void BikerEnemy::move()
{
    setPos(x() - 18, y());
}
