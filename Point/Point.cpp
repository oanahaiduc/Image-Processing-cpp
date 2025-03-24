#include "Point.h"

Point::Point() {
    this->xCoord = 0;
    this->yCoord = 0;
}

Point::Point(int xCoord, int yCoord){
    this->xCoord = xCoord;
    this->yCoord = yCoord;
}

int Point::getXCoord() const {
    return xCoord;
}

void Point::setXCoord(int xCoord) {
    Point::xCoord = xCoord;
}

int Point::getYCoord() const {
    return yCoord;
}

void Point::setYCoord(int yCoord) {
    Point::yCoord = yCoord;
}

