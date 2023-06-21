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
    }
}
