#include "biker_enemy.h"


BikerEnemy::BikerEnemy() : Enemy()
{
    int random_number = rand() % 2;
    if (random_number == 0)
    {
        setPixmap(QPixmap(":/sprites/Motorcycle_Enemy.png"));
        damage_value = 30;
        point_value = 50;
    }
    else if (random_number == 1)
    {
        setPixmap(QPixmap(":/sprites/Motorcycle_Knife_Enemy.png"));
        damage_value = 45;
        point_value = 70;
    }
}

void BikerEnemy::move()
{
    setPos(x(), y() + 18);
    //Delete it if it goes past the bottom
    if (pos().y() > 600)
    {
        scene()->removeItem(this);
        delete this;
    }
}
