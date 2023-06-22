#ifndef ASTEROID_H
#define ASTEROID_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QRandomGenerator>
#include <QImage>
#include <QTimer>


class Asteroid: public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Asteroid(QObject*);
    void destructAsteroid();  // ??????????// realize explosion / flash  and delete image of asteroid from graphicScene

    QTimer *timer;

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int whichLine;
    int speed;
    QImage imageOfAsteroid;

    const QRectF firstLine = QRectF(QPoint(90.5,-100), QPoint(190.5, 0));
    const QRectF secondLine = QRectF(QPoint(340.5,-100), QPoint(440.5, 0));
    const QRectF thirdLine = QRectF(QPoint(590.5,-100), QPoint(690.5, 0));

private slots:
    void moveAsteroid();
};

#endif // ASTEROID_H
