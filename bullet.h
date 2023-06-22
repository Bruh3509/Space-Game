#ifndef BULLET_H
#define BULLET_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPainter>
#include <QtDebug>
class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Bullet(QPointF);
    ~Bullet();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private slots:
    void move();
private:
    QTimer *timer;
    float gliderXPos;
    float gliderYPos;
};

#endif // BULLET_H
