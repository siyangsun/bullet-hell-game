#-------------------------------------------------
#
# Project created by QtCreator 2017-03-10T16:10:32
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bullet-hell-game
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        player.cpp \
    bullet.cpp \
    enemy.cpp \
    melee_enemy.cpp \
    game.cpp \
    player.cpp \
    score.cpp \
    playerhp.cpp \
    bullet_enemy.cpp \
    biker_enemy.cpp \
    obstacle.cpp \
    powerup.cpp

HEADERS  += player.h \
    bullet.h \
    enemy.h \
    game.h \
    player.h \
    score.h \
    playerhp.h \
    bullet_enemy.h \
    biker_enemy.h \
    melee_enemy.h \
    obstacle.h \
    powerup.h

RESOURCES += \
    resources.qrc
