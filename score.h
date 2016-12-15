#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsItem>

class Score: public QGraphicsTextItem
{
private:
    int score = 0;
public:
    Score(QGraphicsItem* parent = 0);
    int getScore();
    void increase();
};

#endif // SCORE_H
