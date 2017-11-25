#include <QApplication>
#include "Game.h"

/*
 * Le game est global est peut-être accédé partout.
 * On y accéde en précisant le lien vers le pointeur game.
 * #include "game.h"
 * extern Game * game;
 */

Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}
