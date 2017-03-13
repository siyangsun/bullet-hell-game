#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>

class Enemy : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemy();
    int damage_value = 0;
    int point_value = 10;
public slots:
    virtual void move();
};

#endif // ENEMY_H
