#include <QApplication>
#include "game.h"
#include "menu.h"

//declare game as a global object
Game *game;
Menu *menu;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    menu = new Menu();
    menu->show();

    return a.exec();
}
