#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <glider.h>
#include <QtDebug>

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
