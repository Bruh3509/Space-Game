#ifndef GLIDER_H
#define GLIDER_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

enum LINE {left, right};

class Glider : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Glider(QObject*);
    bool changeLine(LINE);
    bool fire();
    QRectF getLine() const;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;

private:
    int curLine;
    int health;
    int bullets;
    //Wrong numbers.
    const QRectF fLine = QRectF(QPoint(90.5,425), QPoint(190.5,525));
    const QRectF sLine = QRectF(QPoint(340.5,425), QPoint(440.5,525));
    const QRectF thLine = QRectF(QPoint(590.5,425), QPoint(690.5,525));
};

#endif // GLIDER_H
