#include "glider.h"

Glider::Glider(QObject *parent) : QObject(parent), QGraphicsItem()
{
    curLine = 2;
    bullets = 4;
    health = 3;

    collisionTimer = std::make_unique<QTimer>();
    collisionTimer->setInterval(100);
    QObject::connect(collisionTimer.get(), &QTimer::timeout, this, [this](){ emit collisionCheck(); });
    collisionTimer->start();
}

bool Glider::changeLine(LINE l)
{
    switch (l)
    {
    case LINE::left:
        if (curLine != 1) {
            --curLine;
            return true;
        } else
            return false;
    case LINE::right:
        if (curLine != 3) {
            ++curLine;
            return true;
        } else
            return false;
    default:
        return false;
    }
}

bool Glider::fire()
{
    if (bullets != 0 ) {
        --bullets;
        return true;
    } else
        return false;
}

void Glider::connection(IncomingObject *collObj)
{
    qDebug() << "collision with glider";
    collObj->connectWithGlider(health, bullets);
    if (health == 0)
        delete this; // TODO
}

QRectF Glider::getLine() const
{
    switch (curLine)
    {
    case 1:
        return fLine;
    case 2:
        return sLine;
    case 3:
        return thLine;
    default:
        return sLine;
    }
}

void Glider::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QImage image(":/gliderIm/ship.png");
    painter->drawImage(sLine, image);
}

QRectF Glider::boundingRect() const
{
    return sLine;
}
