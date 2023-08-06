#ifndef UFOBULLET_H
#define UFOBULLET_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QRandomGenerator>
#include <QImage>
#include <QTimer>
#include <QtDebug>
#include <incomingobject.h>


class UfoBullet: public QObject,  public IncomingObject
{
    Q_OBJECT

public:

    UfoBullet(QPointF, QObject*);
    void connectWithGlider(int&, int&) const override;
    void connectWithBullet() override {};

private:
    std::unique_ptr<QTimer> ufoBulletTimer;
    int bulletCordX;
    int bulletCordY;
    const QRectF firstLine = QRectF(QPointF(90.5,-100), QPointF(190.5, 0));
    const QRectF secondLine = QRectF(QPointF(340.5,-100), QPointF(440.5, 0));
    const QRectF thirdLine = QRectF(QPointF(590.5,-100), QPointF(690.5, 0));

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private slots:
    void moveUfoBullet();
};

#endif // UFOBULLET_H
