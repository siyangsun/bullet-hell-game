#include "powerup.h"
#include "game.h"
#include "player.h"
#include "score.h"
#include "playerhp.h"

extern Game *game();

PowerUp::PowerUp()
{
    int random_number = rand() % 2;
    if (random_number == 0)
    {
        setPixmap(QPixmap(":/sprites/Bandaid.png"));
        damage_value = -50;
        point_value = 0;
    }
    else if (random_number == 1)
    {
        setPixmap(QPixmap(":/sprites/Money.png"));
        damage_value = 0;
        point_value = 100;
    }
}
