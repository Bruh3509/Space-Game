#ifndef INCOMINGOBJECT_H
#define INCOMINGOBJECT_H
#include <QGraphicsItem>
#include <QObject>

class IncomingObject
{
    QOBJECT_H
public:
    IncomingObject();
    virtual void connectWithGlider(int&, int&) = 0;
};

#endif // INCOMINGOBJECT_H
