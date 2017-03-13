#include <QApplication>
#include "game.h"

//declare game as a global object
Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}
