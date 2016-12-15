#ifndef MISIL_H
#define MISIL_H

#include <QGraphicsRectItem>
#include <QObject>//slots

class Misil : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
  public:
    /// Constructor
    Misil();

  private:
    void posicionar_derecha();
    void posicionar_izquierda();
    bool disparar_derecha = false;

  public slots:
    void move();
};

#endif // MISIL_H
