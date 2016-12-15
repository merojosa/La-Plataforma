#include "controlador.h"
#include "cubo.h"
#include "misil.h"
#include "sierra.h"
#include "powers.h"

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

void Controlador::spawn_sierras()
{
    Sierra* sierra = new Sierra();
    scene()->addItem(sierra);
}

void Controlador::spawn_powers()
{
    Powers* powers = new Powers();
    scene()->addItem(powers);
}
