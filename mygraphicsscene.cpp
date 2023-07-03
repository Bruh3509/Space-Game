#include "mygraphicsscene.h"

MyGraphicsScene::MyGraphicsScene()
{
    this->glider = new Glider(this);
    addItem(this->glider);
    collisionTimer = new QTimer();
    collisionTimer->setInterval(3000);
    QObject::connect(collisionTimer, SIGNAL(timeout()), this, SLOT(isCollidesAWB()));
    collisionTimer->start();
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
        // ToDo delete bullets!!!
        if (glider->fire()) {
            collisionTimer->stop();
            QPointF pt = QPointF(glider->getLine().center());
            Bullet *blt = new Bullet(pt);
            addItem(blt);
            bulletsStash.push_back(blt);
            QObject::connect(this, &MyGraphicsScene::awbCollision, [=](){ qDebug() << "collides"; }); // ToDO logic in deletion.
            collisionTimer->start(3000);
        }
        break;
    case Qt::Key_Q:
        this->asteroid = new Asteroid(this); // We do not need to save 1 obj. (the same with the bullets),
                                             //I'll make the asteroid stash instead.
        addItem(this->asteroid);
        asteroidStash.push_back(this->asteroid);
    }
}

void MyGraphicsScene::isCollidesAWB()
{
    emit awbCollision();
}
