#ifndef UFO_H
#define UFO_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QRandomGenerator>
#include <QImage>
#include <QTimer>
#include <incomingobject.h>
#include <ufobullet.h>

class Ufo: public QObject,  public IncomingObject
{
    Q_OBJECT

public:
    Ufo(QObject*);
    void connectWithGlider(int&, int&) const override{};
    void connectWithBullet() override;
    ~Ufo();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QTimer *ufoTimer;
    QTimer *shootTimer;
    int line;
    int curLine;
    int newLine;
    int ufoTimerValue = 3000;
    const QRectF firstLine = QRectF(QPointF(90.5,-100), QPointF(190.5, 0));
    const QRectF secondLine = QRectF(QPointF(340.5,-100), QPointF(440.5, 0));
    const QRectF thirdLine = QRectF(QPointF(590.5,-100), QPointF(690.5, 0));

private slots:
    void moveUfoDown();
    void whereMoveUfo();
    void moveUfo();
    void shoot();

signals:
    void shooted(Ufo*);

};

#endif // UFO_H
