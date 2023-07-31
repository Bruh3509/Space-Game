#include "movingmonster.h"

MovingMonster::MovingMonster(QObject *parent): QObject(parent), IncomingObject()
{
    this->line = QRandomGenerator::global()->bounded(3) + 1;

    speedTimer = new QTimer();
    speedTimer->setInterval(30);
    speedTimer->start();
    QObject::connect(speedTimer, SIGNAL(timeout()), this, SLOT(move()));
}

QRectF MovingMonster::boundingRect() const{
    switch (this->line) {
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

void MovingMonster::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    Q_UNUSED(option)
    Q_UNUSED(widget)

    switch (blackHoleIndicator){
    case 1:
        painter->drawImage(boundingRect(), QImage(":/movingMonster/black.png"));
        QTimer::singleShot(85, this, SLOT(hideBlackHole()));
        return;

    case 2:
        painter->drawImage(boundingRect(), QImage(":/movingMonster/black.png"));
        return;

    default:
        break;
    }

    switch (this->line) {
    case 1:
        painter->drawImage(firstLine, QImage(":/movingMonster/moon.png"));
        break;

    case 2:
        painter->drawImage(secondLine, QImage(":/movingMonster/moon.png"));
        break;

    case 3:
        painter->drawImage(thirdLine, QImage(":/movingMonster/moon.png"));
        break;

    default:
        break;
    }
}

void MovingMonster::move(){
    this->moveBy(0, 3);

    if (this->scenePos().y() >= 950){
        this->deleteLater();
    }

    else if ((this->sceneBoundingRect().y() >= 75 && counter == 0) ||
        (this->sceneBoundingRect().y() >= 200 && counter == 1) ||
        (this->sceneBoundingRect().y() >= 325 && counter == 2) ||
        (this->sceneBoundingRect().y() >= 450 && counter == 3)){

        ++counter, blackHoleIndicator = 1;

        QObject::disconnect(speedTimer, SIGNAL(timeout()), this, SLOT(move()));
        QTimer::singleShot(2400, this, SLOT(showBlackHole()));
        QTimer::singleShot(2500, this, SLOT(changeLine()));
    }
}

void MovingMonster::changeLine(){
    blackHoleIndicator = 0;
    QObject::connect(speedTimer, SIGNAL(timeout()), this, SLOT(move()));
}

void MovingMonster::hideBlackHole(){
    this->setVisible(false);
}

void MovingMonster::showBlackHole(){
    setVisible(true);
    this->line = QRandomGenerator::global()->bounded(3) + 1, blackHoleIndicator = 2;
}

void MovingMonster::connectWithGlider(int &HP, int &BULLETS) const
{
    Q_UNUSED(BULLETS)

    --HP;
}

MovingMonster::~MovingMonster(){
    delete speedTimer;
}
