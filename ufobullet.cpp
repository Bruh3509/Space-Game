#include "ufobullet.h"

UfoBullet::UfoBullet(QPointF center, QObject *parent): QObject(parent), IncomingObject()
{
    bulletCordX = center.rx();
    bulletCordY = center.ry();

    this->ufoBulletTimer = std::make_unique<QTimer>();
    ufoBulletTimer->setInterval(20);
    QObject::connect(ufoBulletTimer.get(), SIGNAL(timeout()), this, SLOT(moveUfoBullet()));
    ufoBulletTimer->start();

    qDebug() << "aa";


}

void UfoBullet::moveUfoBullet(){
    moveBy(0, 10);

    if (this->scenePos().y() >= 700){
        delete this;
    }
}

void UfoBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    Q_UNUSED(option)
    Q_UNUSED(widget)

    QImage image(":/gliderIm/bullet.png");
    painter->drawImage(QRectF(QPoint(bulletCordX - 20, bulletCordY - 80), QPointF(bulletCordX + 20, bulletCordY - 50)), image);
}

void UfoBullet::connectWithGlider(int &HP, int &BULLETS) const
{
    Q_UNUSED(BULLETS)

    --HP;
}

QRectF UfoBullet::boundingRect() const
{
    return QRectF(QPoint(bulletCordX - 20, bulletCordY - 80), QPointF(bulletCordX + 20, bulletCordY - 50));
}
