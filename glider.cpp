#include "glider.h"

Glider::Glider()
{
    curLine = 2;
}

void Glider::changeLine(LINE l)
{
    switch (l)
    {
    case left:
        if (curLine != 1)
            --curLine;
        break;
    case right:
        if (curLine != 3)
            ++curLine;
        break;
    }

}

void Glider::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::red);
    painter->setBrush(Qt::green);
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


     //ToDo, draw the right rectangle. From 3;
}

QRectF Glider::boundingRect() const
{
    // ToDo
}
