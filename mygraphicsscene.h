#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QtDebug>
#include <QVector>
#include <QTimer>

#include <glider.h>
#include <bullet.h>
#include <asteroid.h>

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MyGraphicsScene();
signals:
    void repaintGlider(QRectF);
    void awbCollision();
private slots:
    void isCollidesAWB(); // AWB -- Asteroid With Bullet.
protected:
    void keyPressEvent(QKeyEvent *event) override;
private:
    Glider *glider;
    Asteroid *asteroid;
    QVector<Bullet*> bulletsStash;
    QVector<Asteroid*> asteroidStash;
    QTimer *collisionTimer;
};

#endif // MYGRAPHICSSCENE_H
