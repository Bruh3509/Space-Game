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
    Q_INTERFACES(QGraphicsItem)
public:
    Bullet(QPointF, QObject *parent = nullptr);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
signals:
    void moved(Bullet*);
private slots:
    void move();
private:
    std::unique_ptr<QTimer> timer;
    float gliderXPos;
    float gliderYPos;
};

#endif // BULLET_H
