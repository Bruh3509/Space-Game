#include "mygraphicsscene.h"

MyGraphicsScene::MyGraphicsScene()
{
    this->glider = new Glider(this);
    addItem(this->glider);

    this->typeOfBackground = 1 + QRandomGenerator::global()->bounded(4);
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
            QPointF pt = QPointF(glider->getLine().center());
            Bullet *blt = new Bullet(pt);
            addItem(blt);
        }
        break;
    case Qt::Key_Q:
        this->asteroid = new Asteroid(this);
        addItem(this->asteroid);
        break;
    }
}

void MyGraphicsScene::drawBackground(QPainter *painter, const QRectF &rect){
    Q_UNUSED(rect);

    QImage background;
    switch (this->typeOfBackground){
    case 1:
        background = QImage(":/background/background_1.jpg");
        break;
    case 2:
        background = QImage(":/background/background_2.jpg");
        break;
    case 3:
        background = QImage(":/background/background_3.jpg");
        break;
    case 4:
        background = QImage(":/background/background_4.jpg");
        break;
    default:
        break;
    }

    painter->drawImage(sceneRect(), background);
}
