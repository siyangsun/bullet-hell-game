# bullet-hell-game
Project for PIC 10C at UCLA

I've been following this guide: https://www.youtube.com/watch?v=8ntEQpg7gck&t=1s
However, once I get comfortable with the mechanics of the game and with using QT for the project, I will branch off and add my own features to it.

### Instructions
To be safe, cleaning the solution and running qmake before running will prevent errors in the .obj files. Once run, move using the left and right arrow keys, and shoot using space. Avoid getting hit by enemies or obstacles by either dodging or shooting them. You can pick up powerups like bandaids or money to heal or increase your score.

### Process
Using the tutorial above, I created classes for the *Game*, *Player*, *Bullet*, *Enemy*, *Health*, and *Score* (though my own implementation is a little different). *Game* is a QGraphicsWidget that contains all the other objects, and handles playing the game. *Player*, *Bullet*, and *Enemy* are QGraphicsPixmapItem objects, each with their own distinct members. *Player* can accept keypress inputs, while *Bullet* and *Enemy* have their own movement functions. I also referenced the tutorial on how to handle collisions, for the most part- however, I decided to check collisions in the *Enemy* class instead of in the *Bullet* class (how the tutorial did it), since I had other plans for how to handle destroying the objects. I used my previous knowledge of signals and slots to do this. *Health* (which I have named *PlayerHP*) and *Score* are fairly simple QGraphicsTextItem objects that I implemented with the help of the video tutorial. I also referenced the tutorial video series as well as the qt documentation to add resource files into my game.

Currently, I've implemented several different types of enemies: "melee" enemies which cause collision damage, "shooting" enemies which fire projectiles, and "projectile" enemies which are essentially melee enemies that are launched by the shooting enemies. Within the *MeleeEnemy* class there are *Obstacles*, which do not move; I implemented powerups using this as well, which use the built-in private members of the *Enemy* class to increase player score or heal the player by doing negative damage. 
I also changed the way *Enemy* object destruction was handled, in order to allow enemies to take more than one hit of damage by the player. 

In my game, I cleaned up a lot of the code regarding movement and spawning to look cleaner and make more sense. Currently, I am using random number generators from the standard library to spawn different enemies in a random order. Initially, I was using a bunch of if statements to handle this; however, I decided to implement an array of function pointers, which I learned about in class:
```    
int random = rand() % 3;
//We want to create an array of pointers to member functions, and then call a random index from that array
void (Player::*possible_spawns[3])() = {&Player::spawn_obstacle, &Player::spawn_powerup, &Player::spawn_biker};
(this->*possible_spawns[random])();
```


Collisions are checked using the CollidingItems() function. 

```void Enemy::check_collisions()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    //check for collisions
    for (int i = 0; i < colliding_items.size(); ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Bullet))
        {
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            if (hitpoints <= 1)
            {
                die();
            }
            --hitpoints;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            game->player_hp->take_damage(damage_value);
            alive = false;
            return;
        }
    }
}
```

This stores all of an *Enemy*'s collisions in a QList container, in which we check each item to see whether or not the colliding item was a bullet. I'd like to implement this in a different way using iterators or generic algorithms next. Another way I would try to spice up my game is to implement an enemy type that requires copy+swap or something.

### Short Term Bugs
+ Money powerup only gives points when shot, not collected- this is because the way I set it up to give points is as an *Enemy* object  
+ Bandaid powerup can heal more than full, which doesn't really make sense. Also makes the game pretty easy  
+ Weird hitbox on the roadblock sprite  
