#include "sierra.h"
#include "player.h"
#include "info.h"
#include "score.h"

#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <typeinfo>//typeid
#include <stdlib.h> //rand


extern Player* player; //El jugador se hace global ya que será usado en otras clases
extern Score* score; //Se debe acceder en esta clase
extern bool gameOver;

Sierra::Sierra() : QObject(), QGraphicsRectItem()
{
    //225 es la mitad del largo de la plataforma.
    int random_number = rand() % 2;//[0, 1] Para saber si disparo el misil a la derecha o la izquierda

    if( random_number == 0 )//Derecha
    {
        posicionar_derecha();
        derecha = true;
    }
    else                    //Izquierda
        posicionar_izquierda();

    //Dibujo el objeto
    setRect(0, 0, 8, 30);

    //Cambio de color los misiles
    //Cambio de color las sierras
    QBrush brush(Qt::darkGray);
    this->setBrush(brush);

    //Conecto
    QTimer* timer = new QTimer();
    //Cada cierto tiempo, se invocará a move
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(30);//30 milisegundos
}

void Sierra::posicionar_derecha()
{
    setPos( 225, 450 );//El misíl tiene que estar en la posición 420 del eje y.
}

void Sierra::posicionar_izquierda()
{
    setPos( -225, 450 );//390 es la mitad de la ventana
}

void Sierra::move()
{
    QList< QGraphicsItem* > colliding_items = collidingItems();//Lista con todos los Item

    for( int contador = 0; contador < colliding_items.size(); ++contador )
    {
        // Si el misil choca con el jugador.
        if( typeid( *(colliding_items[contador]) ) == typeid(Player) )
        {
            //Muestra el Game Over
            Info* info = new Info();
            scene()->addItem(info);
            info->setPos(info->x()-100, info->y()+300);

            scene()->removeItem(player); //Elimina el jugador (global)

            scene()->removeItem(this);//Saco de escena al misil
            delete this;//Elimino el misil.

            gameOver = true;

            return;
        }
    }

    if( derecha == true )//Si la sierra está a la derecha
        setPos( x() - 5, y());//La muevo hacia la izquierda
    else//Misíl a la izquierda
        setPos( x() + 5, y());//La muevo hacia la derecha

    //Si se sale de la ventana
    if( pos().x() < -225 || pos().x() > 225 )
    {
        if(!gameOver)
            score->increase();

        scene()->removeItem(this);//Lo elimino

        delete this;
    }
}
