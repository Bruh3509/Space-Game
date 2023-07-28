#include "mygraphicsscene.h"

MyGraphicsScene::MyGraphicsScene()
{
    this->glider = new Glider(this);
    addItem(this->glider);

    this->typeOfBackground = 1 + QRandomGenerator::global()->bounded(7);

    this->spawnTimer = new QTimer;
    this->spawnTimer->setInterval(1000); // hardcode (: (maybe need to add a new variable for this value)
    QObject::connect(spawnTimer, SIGNAL(timeout()), this, SLOT(spawnObject()));
    QObject::connect(glider, SIGNAL(gameOver()), this, SLOT(gameOver()));
    QObject::connect(glider, SIGNAL(collisionCheck()), this, SLOT(checkCollisionAWG()));
    spawnTimer->start();

//    this->ufo = new Ufo(this);
//    QObject::connect(ufo, SIGNAL(shooted()))
}

void MyGraphicsScene::spawnObject(){
    int num = 1 + QRandomGenerator::global()->bounded(100);
    if (1 <= num && num <= 70){
        Asteroid *asteroid = new Asteroid(this);
        addItem(asteroid);
    }
    else if (71 <= num && num <= 85){
        num = 1 + QRandomGenerator::global()->bounded(100);
        // spawn UFO
        if (1 <= num && num < 15){
            IncomingObject *ufo;
            ufo = new Ufo(this);
            addItem(ufo);
            QObject::connect(dynamic_cast<Ufo*>(ufo), SIGNAL(shooted(Ufo*)), this, SLOT(spawnUfoBullet(Ufo*)));
        }
        else if (15 <= num && num < 25){
            IncomingObject *movingMonster;
            movingMonster = new MovingMonster(this);
            addItem(movingMonster);
        }
        // spawn another monster
        else{
            qDebug() << "The monster was spawned";
        }
    }
    else if (86 <= num && num <= 90){
        // TODO: create an object of bonus class
        qDebug() << "The bonus was spawned";
    }
    // at some values we can not spawn anything
}

void MyGraphicsScene::keyPressEvent(QKeyEvent *event)
{
    IncomingObject *asteroid;
    IncomingObject *ammo;
   // IncomingObject *ufo;
    IncomingObject *ufoBullet;
    IncomingObject *movingMonster;

    QGraphicsScene::keyPressEvent(event);
    switch (event->key()) {
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
        if (glider->fire()) {
            QPointF pt = QPointF(glider->getLine().center());
            Bullet *blt = new Bullet(pt, this);
            addItem(blt);
            QObject::connect(blt, SIGNAL(moved(Bullet*)), this, SLOT(checkCollisionAWB(Bullet*)));
        }
        break;

    // Just to check theese faetures.
    case Qt::Key_Q:
        asteroid = new Asteroid(this); // We do not need to save the obj., deleted field asteroid.
        addItem(asteroid);
        break;

    case Qt::Key_R:
        ammo = new Ammo(this);
        addItem(ammo);
        break;

    case Qt::Key_Y:
        movingMonster = new MovingMonster(this);
        addItem(movingMonster);
       // movingMonster->setEnabled();
        break;

    case Qt::Key_T:
        Ufo *ufo = new Ufo(this);
        addItem(ufo);
//        ufoBullet = new UfoBullet(QPoint(ufo->scenePos().rx(), ufo->scenePos().ry()), this);
//        addItem(ufoBullet);
        QObject::connect(ufo, SIGNAL(shooted(Ufo*)), this, SLOT(spawnUfoBullet(Ufo*)));
        break;
    }
}

void MyGraphicsScene::spawnUfoBullet(Ufo *ufo){
    IncomingObject *bullet;
//    IncomingObject *ufo;
//    ufo = new Ufo(this);
    bullet = new UfoBullet(QPoint(ufo->sceneBoundingRect().x() + 49, ufo->sceneBoundingRect().y() + 140), this);
    addItem(bullet);
}

void MyGraphicsScene::drawBackground(QPainter *painter, const QRectF &rect){
    Q_UNUSED(rect);

    QImage background;
    switch (this->typeOfBackground) {
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
    case 5:
        background = QImage(":/background/background_5.jpg");
        break;
    case 6:
        background = QImage(":/background/background_6.jpg");
        break;
    case 7:
        background = QImage(":/background/background_7.jpg");
        break;
    default:
        break;
    }

    painter->drawImage(sceneRect(), background);
}

void MyGraphicsScene::checkCollisionAWB(Bullet *blt)
{
    qDebug() << "blt";
    QList<QGraphicsItem*> collisions = this->collidingItems(blt);

    for (auto it : collisions)
        delete it;

    if (!collisions.empty())
        delete blt;
}

void MyGraphicsScene::checkCollisionAWG()
{
    QList<QGraphicsItem*> collisions = this->collidingItems(glider);

    for (auto it : collisions) {
        glider->connection(dynamic_cast<IncomingObject*>(it));
        delete it;
    }
}

void MyGraphicsScene::gameOver()
{
    // Something that happens when I loose.

    // delete glider; //Just to check, not the all logic.
}
