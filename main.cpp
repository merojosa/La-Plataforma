#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include <QGraphicsLineItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Se crea la escena, un jugador, las columnas y la plataforma
    QGraphicsScene* scene = new QGraphicsScene();
    Player* player = new Player();
    QGraphicsRectItem* leftColumn = new QGraphicsRectItem();
    QGraphicsRectItem* rightColumn = new QGraphicsRectItem();
    QGraphicsRectItem* platform = new QGraphicsRectItem();

    //Se asigan los tamaños a las 3 partes de la plataforma
    leftColumn->setRect(-200, 500, 30, 150);
    rightColumn->setRect(200,500,30,150);
    platform->setRect(-250, 480, 550, 20);

    //Se añade cada objeto a la escena.
    scene->addItem(leftColumn);
    scene->addItem(rightColumn);
    scene->addItem(platform);
    scene->addItem(player);

    //Con estas 2 instrucciones el jugador puede captar las flechas del teclado
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Se crea la vista o ventana principal y se muestra
    QGraphicsView* view = new QGraphicsView(scene);
    view->show();

    //Se actualizan los tamaños de la ventana y la escena
    view->setFixedSize(785,600);
    scene->setSceneRect(-360,30,780,560);

    return a.exec();
}
