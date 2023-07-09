#include "bullet.h"
#define DEBUG
Bullet::Bullet(QPointF gliderPos, QObject *parent) : QObject(parent), QGraphicsItem()
{
    gliderYPos = gliderPos.ry();
    gliderXPos = gliderPos.rx();
    timer = new QTimer();
    timer->setInterval(10);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start();
}

void Bullet::move()
{
    moveBy(0,-10);
    if (this->scenePos().y() <= -680)
        delete this;
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QImage image(":/gliderIm/bullet.png");
    painter->drawImage(QRectF(QPointF(gliderXPos - 20, gliderYPos - 80), QPointF(gliderXPos + 20, gliderYPos - 50)), image);
    emit moved(this);
}

QRectF Bullet::boundingRect() const
{
    return QRectF(QPointF(gliderXPos - 20, gliderYPos - 80), QPointF(gliderXPos + 20, gliderYPos - 50));

}

Bullet::~Bullet()
{
    #ifdef DEBUG
    qDebug() << "timer deleted";
    #endif // DEBUG

    delete timer;
}
