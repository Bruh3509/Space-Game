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
    Glider();
    void changeLine(LINE);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;
    int health;
private:
    int curLine;
    inline static const QRectF fLine = QRectF(QPoint(130,500), QPoint(155,525));
    inline static const QRectF sLine = QRectF(QPoint(388.5,500), QPoint(412.5,525));
    inline static const QRectF thLine = QRectF(QPoint(750,500), QPoint(775,525));
};

#endif // GLIDER_H
