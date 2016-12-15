#include "game.h"
#include "player.h"
#include "controlador.h"
#include "score.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <stdlib.h> //rand

extern Player* player;
Score* score;
QMediaPlayer* music;

void Game::start()
{
    //Se crea la escena, un jugador, las columnas y la plataforma
    QGraphicsScene* scene = new QGraphicsScene();

    QGraphicsRectItem* leftColumn = new QGraphicsRectItem();
    QGraphicsRectItem* rightColumn = new QGraphicsRectItem();
    QGraphicsRectItem* platform = new QGraphicsRectItem();

    //Se asigan los tamaños a las 3 partes de la plataforma
    leftColumn->setRect(-200, 500, 30, 150);
    rightColumn->setRect(200,500,30,150);
    platform->setRect(-250, 480, 550, 20);

    //Cambio el color del rectángulo y la plataforma
    QBrush brush(Qt::blue);
    player->setBrush(brush);

    QBrush brush2(Qt::gray);
    leftColumn->setBrush(brush2);
    rightColumn->setBrush(brush2);
    platform->setBrush(brush2);

    //Añado el puntaje
    score = new Score();
    score->setPos(250,30);
    scene->addItem(score);

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


    //Se añade sonido de fondo
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/Insane-Gameplay.mp3"));
    music->play();

    //Controla la salida de los "enemigos"
    Controlador* controlador = new Controlador();
    scene->addItem(controlador);//Para agregar un objeto a la escena, el controlador debe de estar en la escena.


    //Creo los cubos
    QTimer* timer_cubos = new QTimer();
    QObject::connect( timer_cubos, SIGNAL(timeout()), controlador, SLOT(spawn_cubos()) );
    timer_cubos->start(2000);//2000 milisegundos = 2 segundos, cada 2 segundos manda la sennal.

    //Creo los misiles
    QTimer* timer_misiles = new QTimer();
    QObject::connect( timer_misiles, SIGNAL(timeout()), controlador, SLOT(spawn_misiles()) );
    timer_misiles->start(7000);//7 segundos

    //Creo las sierras
    QTimer* timer_sierras = new QTimer();
    QObject::connect( timer_sierras, SIGNAL(timeout()), controlador, SLOT(spawn_sierras()) );
    timer_sierras->start(17000);//17 segundos

    //Creo los poderes
    QTimer* timer_powers = new QTimer();
    QObject::connect( timer_powers, SIGNAL(timeout()), controlador, SLOT(spawn_powers()) );
    timer_powers->start(5000);//17 segundos
}
