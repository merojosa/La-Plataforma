#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QGraphicsRectItem>
#include <QObject>//slots

class Controlador : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
  public:
    /// Constructor
    Controlador();

  public slots:
    void spawn();
};

#endif // CONTROLADOR_H
