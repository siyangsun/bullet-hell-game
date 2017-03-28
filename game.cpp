#include "game.h"
#include <QDebug>
#include <QBrush>
#include <QImage>

QGraphicsScene *scene;
QGraphicsView *view;


Game::Game(QWidget *parent)
{
    Q_UNUSED(parent);

    // create a scene
    scene = new QGraphicsScene();

    // add a view
    view = new QGraphicsView(scene);
    // can also use view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800 ,600);
    scene->setSceneRect(0, 0, 800, 600);

    //make the background
    view->setBackgroundBrush(QBrush(QImage(":/sprites/Background.png")));

    //create the player
    player = new Player();
    player->setPixmap(QPixmap(":/sprites/motorcycle_guy2.png"));
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(0, (view->height() - player->boundingRect().height()) / 2);

    //draw score
    score = new Score();
    scene->addItem(score);
    //draw hitpoints
    player_hp = new PlayerHP();
    player_hp->setPos(player_hp->x() + 650, player_hp->y());
    scene->addItem(player_hp);
    //connect hp to ending the game
    connect(player_hp, SIGNAL(dead()), this, SLOT(end()));

    //draw the menu
    menu = new Menu();
    scene->addItem(menu);

    //start spawning enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(1000);

    show();
}

/*
Game::~Game()
{
    scene = nullptr;
    player = nullptr;
    int final_score = score->getScore();
    score = nullptr;
    player_hp = nullptr;
}
*/

void Game::end()
{
    //qDebug() << "Successfully quit program";
    //can stop testing health, and can do more extra stuff before exiting
    int& last_game_score = score->score;
    menu = new Menu();
    scene->addItem(menu);
    score->score = 0;
    player_hp->hp = 100;
    //update score and hp
    score->increase(0);
    player_hp->take_damage(0);
    //menu->setPixmap(QPixmap(":/sprites/bandaid.png"));

}
