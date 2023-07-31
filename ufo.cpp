#include "ufo.h"

Ufo::Ufo(QObject *parent): QObject(parent), IncomingObject()
{
    this->line = QRandomGenerator::global()->bounded(3) + 1;

    ufoTimer = new QTimer();
    ufoTimer->setInterval(25);
    QObject::connect(ufoTimer, SIGNAL(timeout()), this, SLOT(moveUfoDown()));
    ufoTimer->start();

    shootTimer = new QTimer();
    shootTimer->setInterval(ufoTimerValue / 2);
}

void Ufo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    Q_UNUSED(option)
    Q_UNUSED(widget)

    switch (this->line) {
    case 1:
        painter->drawImage(firstLine, QImage(":/ufo/ufo.png"));
        //this->line = 1;
        this->curLine = 1;
        break;

    case 2:
        painter->drawImage(secondLine, QImage(":/ufo/ufo.png"));
        //this->line = 2;
        this->curLine = 2;
        break;

    case 3:
        painter->drawImage(thirdLine, QImage(":/ufo/ufo.png"));
        //this->line = 3;
        this->curLine = 3;
        break;

    default: break;
    }
}

QRectF Ufo::boundingRect() const
{
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

void Ufo::moveUfoDown(){
    Ufo::moveBy(0, 4);
    if (this->scenePos().ry() >= 150){
        ufoTimer->setInterval(ufoTimerValue);
        QObject::disconnect(ufoTimer, SIGNAL(timeout()), this, SLOT(moveUfoDown()));
        QObject::connect(ufoTimer, SIGNAL(timeout()), this, SLOT(whereMoveUfo()));

        QObject::connect(shootTimer, SIGNAL(timeout()), this, SLOT(shoot()));
        shootTimer->start();
    }
}

void Ufo::whereMoveUfo(){

    if (newLine == 1 || newLine == 2 || newLine == 3){
        curLine = newLine;
    }
    if (this->curLine == 1){
        this->newLine = 2 + QRandomGenerator::global()->bounded(2);
        curLine = newLine;
    }
    else if (this->curLine == 2){
        this->newLine = QRandomGenerator::global()->bounded(2);
        newLine == 0? newLine = 1: newLine = 3;
        curLine = newLine;
    }
    else if (this->curLine == 3){
        this->newLine = QRandomGenerator::global()->bounded(1) + 2;
        curLine = newLine;
    }

    ufoTimer->setInterval(30);
    QObject::disconnect(ufoTimer, SIGNAL(timeout()), this, SLOT(whereMoveUfo()));
    QObject::connect(ufoTimer, SIGNAL(timeout()), this, SLOT(moveUfo()));
}

void Ufo::moveUfo(){
    if (newLine == 2 && this->sceneBoundingRect().x() < secondLine.left()){
        this->moveBy(3, 0);
        if (this->sceneBoundingRect().x() >= secondLine.left()){
            QObject::disconnect(ufoTimer, SIGNAL(timeout()), this, SLOT(moveUfo()));
            ufoTimer->setInterval(ufoTimerValue);
            QObject::connect(ufoTimer, SIGNAL(timeout()), this, SLOT(whereMoveUfo()));
            QObject::connect(shootTimer, SIGNAL(timeout()), this, SLOT(shoot()));
        }
    }
    else if (this->newLine == 2 && this->sceneBoundingRect().x() > secondLine.left()){
        this->moveBy(-3, 0);
        if (this->sceneBoundingRect().x() <= secondLine.left()){
            QObject::disconnect(ufoTimer, SIGNAL(timeout()), this, SLOT(moveUfo()));
            ufoTimer->setInterval(ufoTimerValue);
            QObject::connect(ufoTimer, SIGNAL(timeout()), this, SLOT(whereMoveUfo()));
            QObject::connect(shootTimer, SIGNAL(timeout()), this, SLOT(shoot()));
        }
    }
    else if (this->newLine == 3){
        this->moveBy(3, 0);
        if (this->sceneBoundingRect().x() >= thirdLine.left()){
            QObject::disconnect(ufoTimer, SIGNAL(timeout()), this, SLOT(moveUfo()));
            ufoTimer->setInterval(ufoTimerValue);
            QObject::connect(ufoTimer, SIGNAL(timeout()), this, SLOT(whereMoveUfo()));
            QObject::connect(shootTimer, SIGNAL(timeout()), this, SLOT(shoot()));
        }
    }
    else if (this->newLine == 1){
        this->moveBy(-3, 0);
        if (this->sceneBoundingRect().x() <= firstLine.left()){
            QObject::disconnect(ufoTimer, SIGNAL(timeout()), this, SLOT(moveUfo()));
            ufoTimer->setInterval(ufoTimerValue);
            QObject::connect(ufoTimer, SIGNAL(timeout()), this, SLOT(whereMoveUfo()));
            QObject::connect(shootTimer, SIGNAL(timeout()), this, SLOT(shoot()));
        }
    }
}

void Ufo::shoot(){
    emit shooted(this);
    QObject::disconnect(shootTimer, SIGNAL(timeout()), this, SLOT(shoot()));
}

void Ufo::connectWithBullet()
{
    this->deleteLater();
}

Ufo::~Ufo(){
    delete ufoTimer;
    delete shootTimer;
}
