#include "mygraphicsscene.h"

MyGraphicsScene::MyGraphicsScene()
{
    this->glider = new Glider(this);
    addItem(this->glider);
    QObject::connect(glider, SIGNAL(gameOver()), this, SLOT(gameOver()));
    QObject::connect(glider, SIGNAL(collisionCheck()), this, SLOT(checkCollisionAWG()));
}

void MyGraphicsScene::keyPressEvent(QKeyEvent *event)
{
    QGraphicsScene::keyPressEvent(event);
    switch(event->key())
    {
    case Qt::Key_D:

        if (glider->changeLine(LINE::right)) {
            glider->moveBy(250, 0);
        }

        break;
            /*
    case Qt::RightArrow:
        if (glider->changeLine(LINE::right)) {
            glider->moveBy(250, 0);
        }
        break;
            */
    case Qt::Key_A:
        if (glider->changeLine(LINE::left)) {
            glider->moveBy(-250, 0);
        }
        break;
        /*
    case Qt::LeftArrow:
        if (glider->changeLine(LINE::left)) {
            glider->moveBy(-250, 0);
        }
        break;
        */
    case Qt::Key_Space:
        if (glider->fire()) {
            QPointF pt = QPointF(glider->getLine().center());
            Bullet *blt = new Bullet(pt, this);
            addItem(blt);
            QObject::connect(blt, SIGNAL(moved(Bullet*)), this, SLOT(checkCollisionAWB(Bullet*)));
        }
        break;
    case Qt::Key_Q:
        IncomingObject *asteroid = new Asteroid(this); // We do not need to save the obj., deleted field asteroid.
        addItem(asteroid);
    }
}

void MyGraphicsScene::checkCollisionAWB(Bullet *blt)
{
    qDebug() << "blt";
    QList<QGraphicsItem*> collisions = this->collidingItems(blt);

    for (auto it : collisions)
        delete it;

    if (!collisions.empty())
        delete blt;
}

void MyGraphicsScene::checkCollisionAWG()
{
    QList<QGraphicsItem*> collisions = this->collidingItems(glider);

    for (auto it : collisions) {
        glider->connection(dynamic_cast<IncomingObject*>(it));
        delete it;
    }
}

void MyGraphicsScene::gameOver()
{
    // Something that happens when I loose.

    // delete glider; //Just to check, not the all logic.
}
