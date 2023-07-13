#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QtDebug>

#include <glider.h>
#include <bullet.h>
#include <asteroid.h>

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MyGraphicsScene();
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    int typeOfBackground{};
    QTimer *spawnTimer;
signals:
    void repaintGlider(QRectF);
protected:
    void keyPressEvent(QKeyEvent *event) override;
private:
    Glider *glider;
    Asteroid *asteroid;
public slots:
    void spawnObject();
};

#endif // MYGRAPHICSSCENE_H
