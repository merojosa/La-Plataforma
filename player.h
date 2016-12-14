#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

class Player : public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent* event);
    //void keyReleaseEvent(QKeyEvent* event);
};

#endif // PLAYER_H
