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
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
    damage_value = 40;
    point_value = 10;
}



void MeleeEnemy::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    //check for collisions
    for (int i = 0; i < colliding_items.size(); ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Bullet))
        {
            game->score->increase(point_value);
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            game->player_hp->take_damage(damage_value);
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    int random_number = rand() % 4;
    setPos(x() + 2 - random_number, y() + 5);
    //Delete it if it goes past the bottom
    if (pos().y() > 600)
    {
        scene()->removeItem(this);
        delete this;
    }

}
