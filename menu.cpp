#include "menu.h"

Menu::Menu()
{
    setPos(75, 30);
    setPixmap(QPixmap(":/sprites/menu.png"));
    damage_value = 0;
    point_value = 0;
}
