#include "bullet.h"

Bullet::Bullet(QRectF gliderPos) : QObject(), QGraphicsItem(), gliderPos(gliderPos)
{
    timer = new QTimer();
    timer->setInterval(10);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start();
}

void Bullet::move()
{
    moveBy(0,-10);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawEllipse(gliderPos);
}

QRectF Bullet::boundingRect() const
{
    return gliderPos;
}
