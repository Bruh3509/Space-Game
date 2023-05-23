#ifndef INCOMINGOBJECT_H
#define INCOMINGOBJECT_H
#include <QGraphicsItem>
#include <QObject>

class IncomingObject : public QObject, public QGraphicsItem
{
    QOBJECT_H
public:
    IncomingObject();
protected:
    float speed;
    QRectF rectSize;
};

#endif // INCOMINGOBJECT_H
