#ifndef BULLET_H
#define BULLET_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPainter>

class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Bullet(QRectF);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private slots:
    void move();
private:
    QTimer *timer;
    QRectF gliderPos;
};

#endif // BULLET_H
