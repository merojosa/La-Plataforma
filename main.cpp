#include "player.h"
#include "game.h"
#include "info.h"

#include <QApplication>

Player* player = new Player(); //} Variables globales para acceder a ellas por medio
Game* game = new Game();       //} de otras clases que las necesitan.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game->start();

    return a.exec();
}
