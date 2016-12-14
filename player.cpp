#include "player.h"
#include <QDebug>

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left) //Izquierda, si esta agachado se levanta.
    {
        if(rect().height() == 30)
        {
            setRect(0,0,30,60); //Cambia el tamaño.
            setY(420); //Coordenada de la plataforma en y.
        }

        setPos(x()-10, y());
    }
    else if(event->key() == Qt::Key_Right) //Derecha, si esta agachado se levanta
    {
        if(rect().height() == 30)
        {
            setRect(0,0,30,60);
            setY(420);
        }

        setPos(x()+10, y());
    }
    else if(event->key() == Qt::Key_Down) //Si está levantado se agacha.
    {
        if(rect().height() != 30)
        {
            if(y() == 0)
                setRect(0,y()+450,30,30);
            else
                setRect(0,30,30,30);
        }

    }
    else if(event->key() == Qt::Key_Up) //Brinca
    {

    }

}
