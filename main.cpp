#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include <QGraphicsLineItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene* scene = new QGraphicsScene();
    Player* player = new Player();
    QGraphicsRectItem* leftColumn = new QGraphicsRectItem();
    QGraphicsRectItem* rightColumn = new QGraphicsRectItem();
    QGraphicsRectItem* platform = new QGraphicsRectItem();
    QGraphicsLineItem* limit = new QGraphicsLineItem();

    leftColumn->setRect(-200, 500, 30, 150);
    rightColumn->setRect(200,500,30,150);
    platform->setRect(-250, 480, 550, 20);

    player->setRect(0,420,30,60);

    limit->setLine(0,0,1,1);

    scene->addItem(leftColumn);
    scene->addItem(rightColumn);
    scene->addItem(platform);
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(limit);

    QGraphicsView* view = new QGraphicsView(scene);
    view->show();

    view->setFixedSize(785,600);
    scene->setSceneRect(-360,30,780,560);

    return a.exec();
}
