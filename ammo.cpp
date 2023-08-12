#include "ammo.h"

Ammo::Ammo(QObject *parent) : QObject(parent),  IncomingObject()
{
    int ammoCount = QRandomGenerator::global()->bounded(INT_MAX);
    if (ammoCount % 3 == 0) {
        ammoBonus = 4;
        image = QImage(":/bullets/bullets.jpg"); // Change the image.
    }
    else {
        ammoBonus = 2;
        image = QImage(":/bullets/bullets.jpg");
    }

    int line = QRandomGenerator::global()->bounded(INT_MAX) % 3;

    switch (line) {
    case 0:
        this->line = QRectF(QPointF(90.5,-100), QPointF(190.5, 0));
        break;
    case 1:
        this->line = QRectF(QPointF(340.5,-100), QPointF(440.5, 0));
        break;
    case 2:
        this->line = QRectF(QPointF(590.5,-100), QPointF(690.5, 0));
        break;
    }

    timer = new QTimer();
    timer->setInterval(10);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start();
}

void Ammo::move()
{
    moveBy(0, 5);

    if (this->scenePos().y() >= 758)
        delete this;

}

void Ammo::connectWithGlider(int &HP, int &BULLETS) const
{
    Q_UNUSED(HP)

    BULLETS += ammoBonus;
}

void Ammo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->drawImage(line, image);
}

QRectF Ammo::boundingRect() const
{
    return line;
}

Ammo::~Ammo()
{
    qDebug() << "ammo deleted";
    delete timer;
}
