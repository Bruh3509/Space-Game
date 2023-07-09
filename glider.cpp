#include "glider.h"

Glider::Glider(QObject *parent) : QObject(parent), QGraphicsItem()
{
    curLine = 2;
    bullets = 4;
    health = 3;
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

void Glider::damaged()
{
    qDebug() << "Got damage";
    --health;
    if (health == 0) {
        // SIGNAL to stop the game.
    }
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
