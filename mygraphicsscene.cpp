#include "mygraphicsscene.h"

MyGraphicsScene::MyGraphicsScene()
{
    this->glider = new Glider(this);
    addItem(this->glider);
}

void MyGraphicsScene::keyPressEvent(QKeyEvent *event)
{
    QGraphicsScene::keyPressEvent(event);
    switch(event->key())
    {
    case Qt::Key_D:
        glider->changeLine(LINE::right);
        glider->moveBy(100,0);
        qDebug() << "D";
        break;
    case Qt::Key_A:
        glider->changeLine(LINE::left);
        glider->moveBy(-100,0);
        qDebug() << "A";
        break;
    }
}
