#ifndef AMMO_H
#define AMMO_H
#include <QObject>
#include <QRandomGenerator>
#include <QPainter>
#include <QImage>
#include <QTimer>
#include <QDebug>
#include <limits>
#include <incomingobject.h>

class Ammo : public QObject,  public IncomingObject
{
    Q_OBJECT
public:
    Ammo(QObject *parent = nullptr);
    void connectWithGlider(int&, int&) const override;
    void connectWithBullet() override {};
    ~Ammo();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private slots:
    void move();

private:
    int ammoBonus;
    QImage image;
    QRectF line;

    QTimer *timer;
};

#endif // AMMO_H
