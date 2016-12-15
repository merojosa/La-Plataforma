#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

class Player : public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent* event);
    //void keyReleaseEvent(QKeyEvent* event);

  public slots:
    //Para crear los cubos en memoria dinámica
    void spawn();
};

#endif // PLAYER_H
