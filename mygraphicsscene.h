#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QtDebug>
#include <QVector>
#include <QTimer>
#include <incomingobject.h>
#include <glider.h>
#include <bullet.h>
#include <asteroid.h>
#include <ammo.h>

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MyGraphicsScene();
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    
signals:
    void repaintGlider(QRectF);

private slots:
    void checkCollisionAWB(Bullet*); // AWB - Asteroid with Bullet.
    void checkCollisionAWG(); // AWG - Asteroid with Glider.
    void gameOver();
    void spawnObject();

protected:
    void keyPressEvent(QKeyEvent *event) override;
private:
    Glider *glider;
    QTimer *collisionTimer();
    Asteroid *asteroid;
    int typeOfBackground{};
    QTimer *spawnTimer;
};

#endif // MYGRAPHICSSCENE_H
