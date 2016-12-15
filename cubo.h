#ifndef CUBO_H
#define CUBO_H

#include <QGraphicsRectItem>
#include <QObject>//slots

//IMPORTANTE: se me hace útil para disparar los cubos, las sierras y los misiles.  Note que la posición de la bala se pone en MyRect.cpp
class Cubo : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
  public:
    /// Constructor
    Cubo();

  public slots:
    void move();
};

#endif // CUBO_H
