#ifndef SIERRA_H
#define SIERRA_H


#include <QGraphicsRectItem>
#include <QObject>//slots

class Sierra : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
  public:
    /// Constructor
    Sierra();

  private:
    void posicionar_derecha();
    void posicionar_izquierda();
    bool derecha = false;

  public slots:
    void move();
};

#endif // SIERRA_H
