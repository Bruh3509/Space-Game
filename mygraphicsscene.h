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
private slots:
    void checkCollisionAWB(Bullet*); // AWB - Asteroid with Bullet.
    void gameOver();
protected:
    void keyPressEvent(QKeyEvent *event) override;
private:
    Glider *glider;
    QTimer *collisionTimer();
};

#endif // MYGRAPHICSSCENE_H
