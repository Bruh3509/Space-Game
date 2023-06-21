#ifndef ASTEROID_H
#define ASTEROID_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QRandomGenerator>
#include <QImage>


class Asteroid: public QObject, public QGraphicsItem
{
public:
    Asteroid();
    void destructAsteroid();  // realize explosion / flash  and delete image of asteroid from graphicScene
    void spawnAsteroid();

private:
    int typeOfAsteroid;
    int whichLine;
    int speed;
    QImage imageOfAsteroid;
};

#endif // ASTEROID_H
