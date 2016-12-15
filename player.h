#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>

class Player : public QObject, public QGraphicsRectItem
{
private:
    QTimer* timer;
    Q_OBJECT
public:
    Player(); //Constructor por defecto
    void keyPressEvent(QKeyEvent* event); //Se activa al presionar una flecha del teclado, cada flecha hace algo diferente

public slots:
    void ascend(); //Se activa al presionar la flecha arriba, asciende.
    void fall(); //Al presionar la flecha arriba, luego de ascender, baja.
    void fallDown(); //Se activa al caer de la plataforma.
};

#endif // PLAYER_H
