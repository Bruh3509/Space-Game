#include "glider.h"

Glider::Glider()
{
    curLine = 2;
}

bool Glider::changeLine(LINE l)
{
    switch (l)
    {
    case left:
        if (curLine != 1) {
            --curLine;
            return true;
        } else
            return false;
    case right:
        if (curLine != 3) {
            ++curLine;
            return true;
        } else
            return false;
    }
}

void Glider::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::red);
    painter->setBrush(Qt::green);
    /*
    switch (curLine)
    {
    case 1:
        painter->drawRect(fLine);
        break;
    case 2:
        painter->drawRect(sLine);
        break;
    case 3:
        painter->drawRect(thLine);
        break;
    default:
        painter->drawRect(sLine);
        break;
    }
    */
    painter->drawRect(sLine);
     //ToDo, draw the right rectangle. From 3;
}

QRectF Glider::boundingRect() const
{
    return QRectF(QPoint(388.5,500), QPoint(412.5,525));
}
