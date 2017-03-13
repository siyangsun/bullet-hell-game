#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "bullet.h"
#include "melee_enemy.h"

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0)
        {
            setPos(x()-10,y());
        }
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + rect().width() < 800)
        {
            setPos(x()+10,y());
        }
    }
    else if (event->key() == Qt::Key_Space) {
        //create a bullet
        Bullet *bullet = new Bullet();
        bullet->setPos(x() + (rect().width() / 2) - (bullet->rect().width() / 2), y());
        scene()->addItem(bullet);
        //qDebug() << "bullet created";
    }
}

void Player::spawn_melee()
{
    MeleeEnemy *enemy = new MeleeEnemy();
    scene()->addItem(enemy);
}

void Player::spawn()
{
    spawn_melee();
}
