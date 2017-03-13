#include "melee_enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "game.h"
#include <QList>

extern Game *game;

MeleeEnemy::MeleeEnemy() : Enemy()
{
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}



void MeleeEnemy::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            game->player_hp->take_damage();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x(), y() + 5);
    //Delete it if it goes past the bottom
    if (pos().y() > 600)
    {
        scene()->removeItem(this);
        delete this;
    }

}
