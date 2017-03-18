#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();
    int damage_value = 0;
    int point_value = 10;
    int hitpoints = 1;
    bool alive = true;
public slots:
    void start_moving();
    virtual void move();
    void check_collisions();
    virtual void die();
};

#endif // ENEMY_H
