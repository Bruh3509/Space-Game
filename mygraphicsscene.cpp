#include "mygraphicsscene.h"

MyGraphicsScene::MyGraphicsScene(Glider *glider)
{
    this->glider = glider;
    addItem(this->glider);
}

void MyGraphicsScene::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_D:
        glider->changeLine(LINE::right);
        emit repaintGlider(QRectF(QPoint(0,0), QPoint(800,600)));
        break;
    case Qt::Key_A:
        glider->changeLine(LINE::left);
        emit sceneRectChanged(QRectF(QPoint(0,0), QPoint(800,600)));
        break;
    }
}
