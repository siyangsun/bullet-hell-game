#include "game.h"


Game::Game(QWidget *parent)
{
    Q_UNUSED(parent);


    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();
    // add a view
    QGraphicsView *view = new QGraphicsView(scene);
    // can also use view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800 ,600);
    scene->setSceneRect(0, 0, 800, 600);

    //create the player
    player = new Player();
    player->setRect(0, 0, 50, 50);
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(view->width() / 2 - (player->rect().width() / 2), view->height() - player->rect().height());

    //draw score
    score = new Score();
    scene->addItem(score);
    //draw hitpoints
    player_hp = new PlayerHP();
    player_hp->setPos(player_hp->x() + 650, player_hp->y());
    scene->addItem(player_hp);

    //start spawning enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    show();
}
