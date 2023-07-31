#ifndef INCOMINGOBJECT_H
#define INCOMINGOBJECT_H
#include <QGraphicsItem>
#include <QObject>

class IncomingObject : public QGraphicsItem
{
public:
    IncomingObject();
    virtual void connectWithGlider(int&, int&) const = 0;
    virtual void connectWithBullet() = 0;
};

#endif // INCOMINGOBJECT_H
