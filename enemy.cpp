#include "enemy.h"
#include "game.h"
#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

extern Game *game;

Enemy::Enemy()
{
    //set random spawn location
    int random_number = rand() % 550;
    setPos(900, random_number);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(start_moving()));
    timer->start(50);

}

void Enemy::start_moving()
{
    check_collisions();
    if (alive == false)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
    //Delete it if it goes past the edge
    else if (pos().x() < 0 - boundingRect().width())
    {
        scene()->removeItem(this);
        delete this;
    }
    else
    {
        move();
    }
}

void Enemy::move()
{

}

void Enemy::check_collisions()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    //check for collisions
    for (int i = 0; i < colliding_items.size(); ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Bullet))
        {
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            if (hitpoints <= 1)
            {
                die();
            }
            --hitpoints;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            game->player_hp->take_damage(damage_value);
            alive = false;
            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Menu))
        {
            alive = false;
            return;
        }
    }
}

void Enemy::die()
{
    game->score->increase(point_value);
    alive = false;
}

