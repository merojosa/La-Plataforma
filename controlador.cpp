#include "controlador.h"
#include "cubo.h"
#include "misil.h"

#include <QDebug>
#include <QGraphicsScene>

Controlador::Controlador()
{
}

void Controlador::spawn_cubos()
{
    //Creo el enemigo
    Cubo* cubo = new Cubo();

    //Agrego el enemigo a la escena
    scene()->addItem(cubo);
}

void Controlador::spawn_misiles()
{
    Misil* misil = new Misil();
    scene()->addItem(misil);
}
