#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QtDebug>

#include <glider.h>
#include <bullet.h>

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MyGraphicsScene();
signals:
    void repaintGlider(QRectF);
protected:
    void keyPressEvent(QKeyEvent *event) override;
private:
    Glider *glider;
};

#endif // MYGRAPHICSSCENE_H
