#include "info.h"
#include <QFont>

Info::Info(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    setPlainText("Game Over");
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 32));
}
