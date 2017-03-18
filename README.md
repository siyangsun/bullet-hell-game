# bullet-hell-game
Project for PIC 10C at UCLA
-
I've been following this guide: https://www.youtube.com/watch?v=8ntEQpg7gck&t=1s
However, once I get comfortable with the mechanics of the game and with using QT for the project, I will branch off and add my own features to it.
-
### Process
Using the tutorial above, I created classes for the Game, Player, Bullet, Enemy, Health, and Score (though my own implementation is a little different). Game is a QGraphicsWidget that contains all the other objects, and handles playing the game. Player, Bullet, and Enemy are QGraphicsPixmapItem objects, each with their own distinct members. Player can accept keypress inputs, while Bullet and Enemy have their own movement functions. I also referenced the tutorial on how to handle collisions, for the most part- however, I decided to check collisions in the Enemy class instead of in the Bullet class (like the tutorial did it), since I had other plans for how to handle destroying the objects. Health (which I have named PlayerHP) and Score are fairly simple QGraphicsTextItem objects that I implemented with the help of the video tutorial. I also referenced the tutorial video series as well as the qt documentation to add resource files into my game.

Currently, I've implemented several different types of enemies: "melee" enemies which cause collision damage, "shooting" enemies which fire projectiles, and "projectile" enemies which are essentially melee enemies that are launched by the shooting enemies. Within the MeleeEnemy class there are Obstacles, which do not move; I implemented powerups using this as well, which use the built-in private members of the enemy class to increase player score or heal the player by doing negative damage. 
I also changed the way Enemy object destruction was handled, in order to allow enemies to take more than one hit of damage by the player. 

In my game, I cleaned up a lot of the code regarding movement and spawning to look cleaner and make more sense. Currently, I am using random number generators from the standard library to spawn different enemies in a random order. In the future I would want to implement a list with a random access iterator or something to pull out an object for spawning, or something cool like that. I also want the game to scale in difficulty based on score, so I am looking to implement a clever algorithm to handle that using concepts I've learned in class.
