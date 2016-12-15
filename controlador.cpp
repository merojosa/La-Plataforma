#include "controlador.h"
#include "cubo.h"

#include <QDebug>
#include <QGraphicsScene>

Controlador::Controlador()
{

}

void Controlador::spawn()
{
    //Creo el enemigo
    Cubo* cubo = new Cubo();

    //Agrego el enemigo a la escena
    scene()->addItem(cubo);
 //   scene->addItem(cubo);
}
