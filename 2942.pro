#-------------------------------------------------
#
# Project created by QtCreator 2017-11-23T16:20:39
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2942
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    bullet.cpp \
    Player.cpp \
    enemy.cpp \
    constants.cpp \
    game.cpp \
    score.cpp \
    spawner.cpp \
    enemygreen.cpp \
    enemyred.cpp \
    particleeffect.cpp \
    sprite.cpp \
    healthUI.cpp \
    bulletplayer.cpp \
    bulletenemy.cpp \
    enemy_firing.cpp \
    highscores.cpp \
    spacerock.cpp \
    enemyblue.cpp \
    powerup.cpp \
    poweruphealth.cpp \
    powerupscore.cpp

HEADERS += \
    bullet.h \
    Player.h \
    enemy.h \
    constants.h \
    game.h \
    score.h \
    playerstats.h \
    spawner.h \
    enemygreen.h \
    enemyred.h \
    particleeffect.h \
    sprite.h \
    healthUI.h \
    bulletenemy.h \
    bulletplayer.h \
    enemy_firing.h \
    highscores.h \
    spacerock.h \
    enemyblue.h \
    powerup.h \
    poweruphealth.h \
    powerupscore.h

RESOURCES += \
    ressources.qrc

DISTFILES += \
    vagues.spwn
