#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 20));
}

int Score::getScore()
{
    return score;
}

void Score::increase()
{
    setPlainText(QString("Score: ") + QString::number(++score));
}

