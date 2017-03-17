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
#include "playerhp.h"


class Game : public QGraphicsWidget
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);
    ~Game();
    QGraphicsScene *scene;
    Player *player;
    Score *score;
    PlayerHP *player_hp;
public slots:
    void end();
};

#endif // GAME_H
