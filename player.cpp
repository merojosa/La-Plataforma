#include "player.h"
#include <QDebug>

bool jumping = false;

Player::Player()
{
    setRect(0,420,30,60); //Se crea el jugador en las coordenadas 0,420 con tamaño 30,60
}

void Player::keyPressEvent(QKeyEvent *event)
{
    timer = new QTimer();

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
            setRect(0,0,30,60); //Aumenta el tamaño
            setY(420); //Coordenada de la plataforma en y.
        }

        setPos(x()+10, y());
    }
    else if(event->key() == Qt::Key_Down) //Si está levantado se agacha.
    {
        if(rect().height() != 30) //Si la altura no es 30 ( es 60 )
        {
            if(y() == 0)
                setRect(0,y()+450,30,30);
            else
                setRect(0,30,30,30);
        }

    }
    else if(event->key() == Qt::Key_Up) //Brinca
    {
        if(y() == 0 || y() == 420)
        {
            if(jumping == false)
            {
                connect(timer, SIGNAL(timeout()), this, SLOT(ascend()));
                timer->start(35);

                if(y() == -40 || y() == 380)
                    timer->stop();

                jumping = true;
            }

        }
    }
}

void Player::ascend()
{
    if(y() <= 0 && y() > -40)
        this->setPos(x(), y()-2);
    else if(y() <= 420 && y() > 380)
        this->setPos(x(), y()-2);

    if(y()==-40 || y() == 380)
    {
        timer->stop();

        connect(timer, SIGNAL(timeout()), this, SLOT(fall()));
        timer->start(40);
    }

    qDebug() << y();
}

void Player::fall()
{
    if(y() < 0 && y() < 420)
        this->setPos(x(), y()+2);

    if(y() == 0 || y() == 420)
        timer->stop();

    jumping = false;
}


