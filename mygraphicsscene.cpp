#include "mygraphicsscene.h"

MyGraphicsScene::MyGraphicsScene()
{
    this->glider = new Glider(this);
    addItem(this->glider);

    this->typeOfBackground = 1 + QRandomGenerator::global()->bounded(4);

    this->spawnTimer = new QTimer;
    this->spawnTimer->setInterval(1000); // hardcode (: (maybe need to add a new variable for this value)
    QObject::connect(spawnTimer, SIGNAL(timeout()), this, SLOT(spawnObject()));
    spawnTimer->start();
}

void MyGraphicsScene::spawnObject(){
    int num = 1 + QRandomGenerator::global()->bounded(100);
    if (1 <= num && num <= 70){
        Asteroid *asteroid = new Asteroid(this);
        addItem(asteroid);
    }
    else if (71 <= num && num <= 85){
        // TODO: create an object of monster class
        qDebug() << "The monster was spawned";
    }
    else if (86 <= num && num <= 90){
        // TODO: create an object of bonus class
        qDebug() << "The bonus was spawned";
    }
    // at some values we can not spawn anything
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
