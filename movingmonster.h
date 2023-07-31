#ifndef MOVINGMONSTER_H
#define MOVINGMONSTER_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QRandomGenerator>
#include <QImage>
#include <QTimer>
#include <incomingobject.h>


class MovingMonster: public QObject,  public IncomingObject
{
    Q_OBJECT

public:
    MovingMonster(QObject*);
    void connectWithGlider(int&, int&) const override;
    void connectWithBullet() override;
    ~MovingMonster();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int line;
    int counter = 0; //check the slot "move"
    int blackHoleIndicator = 0; //needs to understand where we should show or hide the black hole (it is used in the method "paint")
    QTimer *speedTimer;

    const QRectF firstLine = QRectF(QPointF(50.5,-150), QPointF(230.5, 30));
    const QRectF secondLine = QRectF(QPointF(300.5,-150), QPointF(480.5, 30));
    const QRectF thirdLine = QRectF(QPointF(550.5,-150), QPointF(730.5, 30));

private slots:
    void move();
    void changeLine();
    void hideBlackHole();
    void showBlackHole();
};

#endif // MOVINGMONSTER_H
