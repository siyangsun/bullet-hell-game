#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "bullet.h"
#include "melee_enemy.h"
#include "obstacle.h"
#include "bullet_enemy.h"
#include "biker_enemy.h"
#include "powerup.h"
#include <stdlib.h>
#include "game.h"

extern Game *game;

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0)
        {
            setPos(x()-10,y());
        }
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + boundingRect().width() < 800)
        {
            setPos(x()+10,y());
        }
    }
    else if (event->key() == Qt::Key_Space) {
        //create a bullet
        Bullet *bullet = new Bullet();
        bullet->setPos(x() + (boundingRect().width() / 2 + 3), y() - 10);
        scene()->addItem(bullet);
        //qDebug() << "bullet created";
    }
}

void Player::spawn_melee()
{
    MeleeEnemy *enemy = new MeleeEnemy();
    scene()->addItem(enemy);
}

void Player::spawn_obstacle()
{
    Obstacle *obstacle = new Obstacle();
    scene()->addItem(obstacle);
}

void Player::spawn_powerup()
{
    PowerUp *powerup = new PowerUp();
    scene()->addItem(powerup);
}

void Player::spawn_biker()
{
    BikerEnemy *enemy = new BikerEnemy();
    scene()->addItem(enemy);
}

void Player::spawn()
{
    int random = rand() % 3;
    //We want to create an array of pointers to member functions, and then call a random index from that array
    void (Player::*possible_spawns[3])() = {&Player::spawn_obstacle, &Player::spawn_powerup, &Player::spawn_biker};
    (this->*possible_spawns[random])();
    /*
    if (random == 0)
    {
        spawn_obstacle();
    }
    else if (random == 1)
    {
        spawn_powerup();
    }
    else
    {
        spawn_biker();
    }
    */
}

//We can elaborate on this more later, but the idea is to make the game harder based on the difficulty.
//We put this variable in the player class so we can access the spawn functionality
//Because of this, we have to maintain the same spawn rate of each enemy
//So we must figure out a way to increase difficulty without having higher quantity of enemies
//Might be better if difficulty is an int from 1 to 5 or something. We can also give the player
//more ways to fight enemies.
double difficulty() {
    double difficulty = game->score->getScore() / 100;
    return difficulty;
}
