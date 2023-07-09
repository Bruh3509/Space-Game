#ifndef GLIDER_H
#define GLIDER_H
#include <QDebug>
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

enum class LINE {left, right};

class Glider : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Glider(QObject*);
    bool changeLine(LINE);
    bool fire();
    void damaged();
    QRectF getLine() const;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;

private:
    int curLine;
    int health;
    int bullets;
    // I change number.
    const QRectF fLine = QRectF(QPoint(83,625), QPoint(183,725));
    const QRectF sLine = QRectF(QPoint(333,625), QPoint(433,725));
    const QRectF thLine = QRectF(QPoint(583,625), QPoint(683,725));
};

#endif // GLIDER_H
