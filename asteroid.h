#ifndef ASTEROID_H
#define ASTEROID_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QRandomGenerator>
#include <QImage>
#include <QTimer>
#include <incomingobject.h>

class Asteroid: public QObject, public QGraphicsItem, protected IncomingObject
{
    Q_OBJECT

public:
    Asteroid(QObject*);
    void destructAsteroid();  // ??????????// realize explosion / flash  and delete image of asteroid from graphicScene

    QTimer *timer;
    void connectWithGlider(int&, int&) override;

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int whichLine;
    int speed;
    QImage imageOfAsteroid;

    const QRectF firstLine = QRectF(QPointF(90.5,-100), QPointF(190.5, 0));
    const QRectF secondLine = QRectF(QPointF(340.5,-100), QPointF(440.5, 0));
    const QRectF thirdLine = QRectF(QPointF(590.5,-100), QPointF(690.5, 0));

private slots:
    void moveAsteroid();
};

#endif // ASTEROID_H
