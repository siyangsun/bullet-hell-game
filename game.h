#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsWidget>
#include <QGraphicsScene>
#include "player.h"
#include "enemy.h"
#include "melee_enemy.h"
#include <QGraphicsView>
#include <QTimer>
#include "score.h"


class Game : public QGraphicsWidget
{
public:
    Game(QWidget *parent = 0);

    QGraphicsScene *scene;
    Player *player;
    Score *score;
};

#endif // GAME_H
