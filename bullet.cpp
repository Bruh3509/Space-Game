#include "bullet.h"

Bullet::Bullet(QPointF gliderPos) : QObject(), QGraphicsItem()
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
        //qDebug() << this->y();
        delete this;
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QImage image(":/gliderIm/bullet.png");
    painter->drawImage(QRectF(QPointF(gliderXPos - 20, gliderYPos - 70), QPointF(gliderXPos + 20, gliderYPos - 40)), image);
    //painter->drawEllipse();
}

QRectF Bullet::boundingRect() const
{
    return QRectF(QPointF(gliderXPos - 20, gliderYPos - 70), QPointF(gliderXPos + 20, gliderYPos - 40));

}

Bullet::~Bullet()
{
    qDebug() << "timer deleted";
    delete timer;
}
