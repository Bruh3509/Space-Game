#include "asteroid.h"

Asteroid::Asteroid()
{
    int type = QRandomGenerator::global()->bounded(3);
    int line = QRandomGenerator::global()->bounded(2) + 1;   // the line is ranked from 1 to 3
    int speed = QRandomGenerator::global()->bounded(5) + 1;

    this->typeOfAsteroid = type;
    this->whichLine = line;
    this->speed = speed;
}

void Asteroid::destructAsteroid()
{

}

void Asteroid::spawnAsteroid(){
    /*
    switch(this->line){
    case 1:

        break;

    case 2:

        break;

    case 3:

        break;

    default: break;

    }
    */
}
