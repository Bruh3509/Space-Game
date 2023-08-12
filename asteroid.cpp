#include "asteroid.h"

Asteroid::Asteroid(QObject *parent): QObject(parent), IncomingObject()
{
    int type = QRandomGenerator::global()->bounded(3);
    int line = QRandomGenerator::global()->bounded(3) + 1;   // the line is ranked from 1 to 3
    int speed = QRandomGenerator::global()->bounded(3) + 1;

    this->whichLine = line;
    this->speed = speed;
    this->imageOfAsteroid = QImage(":/asteroid/asteroid_0.png");

    switch(type){
    case 0:
        this->imageOfAsteroid = QImage(":/asteroid/asteroid_0.png");
        break;
    case 1:
        this->imageOfAsteroid = QImage(":/asteroid/asteroid_1.png");
        break;
    case 2:
        this->imageOfAsteroid = QImage(":/asteroid/asteroid_2.png");
        break;

    default: break;
    }

    timer = new QTimer();
    timer->setInterval(15);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(moveAsteroid()));
    timer->start();
}

void Asteroid::moveAsteroid()
{
    Asteroid::moveBy(0, this->speed);
    if (this->scenePos().y() >= 860)
        delete this;
}

void Asteroid::destructAsteroid()
{

}


void Asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

        Q_UNUSED(option)
        Q_UNUSED(widget)


        switch (this->whichLine) {
        case 1:
            painter->drawImage(firstLine, this->imageOfAsteroid);
        break;

        case 2:
            painter->drawImage(secondLine, this->imageOfAsteroid);
        break;

        case 3:
            painter->drawImage(thirdLine, this->imageOfAsteroid);
        break;

        default: break;
        }
}

QRectF Asteroid::boundingRect() const
{
        switch (this->whichLine) {
        case 1:
            return firstLine;
        case 2:
            return secondLine;
        case 3:
            return thirdLine;
        default:
            return secondLine;
        }
}

void Asteroid::connectWithGlider(int &HP, int &BULLETS) const
{
    Q_UNUSED(BULLETS)

    --HP;
}

void Asteroid::connectWithBullet()
{
    delete this;
}

Asteroid::~Asteroid(){
//    #ifdef DEBUG
//    qDebug() << " asteroid was deleted";
//    #endif
    delete timer;
}
