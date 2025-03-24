#include <algorithm>
#include "Rectangle.h"

Rectangle::Rectangle(): xTopLeft(0), yTopLeft(0), width(0), height(0) {}

Rectangle::Rectangle(int xTopLeft, int yTopLeft,  unsigned int width, unsigned int height) :
xTopLeft(xTopLeft),yTopLeft(yTopLeft), width(width), height(height){}

//getters and setters
int Rectangle::getXTopLeft() const {
    return xTopLeft;
}

void Rectangle::setXTopLeft(int xTopLeft) {
    Rectangle::xTopLeft = xTopLeft;
}

int Rectangle::getYLeftCorner() const {
    return yTopLeft;
}

void Rectangle::setYLeftCorner(int yLeftCorner) {
    Rectangle::yTopLeft = yLeftCorner;
}

unsigned int Rectangle::getWidth() const {
    return width;
}

void Rectangle::setWidth(int width) {
    Rectangle::width = width;
}

unsigned int Rectangle::getHeight() const {
    return height;
}

void Rectangle::setHeight(int height) {
    Rectangle::height = height;
}

//operators
Rectangle Rectangle::operator+(const Point &translationPoint) const{
    return Rectangle(xTopLeft + translationPoint.getXCoord(), yTopLeft + translationPoint.getYCoord(), width, height);
}

Rectangle Rectangle::operator-(const Point &translationPoint) const {
    return Rectangle(xTopLeft - translationPoint.getXCoord(), yTopLeft - translationPoint.getYCoord(), width, height);
}

Rectangle Rectangle::operator&(const Rectangle &otherRectangle) const{
    int intersectionXTopLeft = std::max(this->xTopLeft, otherRectangle.getXTopLeft());
    int intersectionYTopLeft = std::max(this->yTopLeft, otherRectangle.getYLeftCorner());
    int intersectionXBottomRight = std::min((this->xTopLeft + this->width), (otherRectangle.getXTopLeft() + otherRectangle.getWidth()));
    int intersectionYBottomRight = std::min((this->yTopLeft + this->height), (otherRectangle.getYLeftCorner() + otherRectangle.getHeight()));

    unsigned int intersectionWidth = std::max(0, intersectionXBottomRight - intersectionXTopLeft);
    unsigned int intersectionHeight = std::max(0, intersectionYBottomRight - intersectionYTopLeft);

    return Rectangle(intersectionXTopLeft, intersectionYTopLeft, intersectionWidth, intersectionHeight);
}

Rectangle Rectangle::operator|(const Rectangle &otherRectangle) const{
    int unionXTopLeft = std::min(this->xTopLeft, otherRectangle.getXTopLeft());
    int unionYTopLeft = std::min(this->yTopLeft, otherRectangle.getYLeftCorner());
    unsigned int unionXBottomRight = std::max(this->xTopLeft + this->width , otherRectangle.getXTopLeft() + otherRectangle.getWidth());
    unsigned int unionYBottomRight = std::max(this->yTopLeft + this->height, otherRectangle.getYLeftCorner() + otherRectangle.getHeight());

    unsigned int unionWidth = unionXBottomRight - unionXTopLeft;
    unsigned int unionHeight = unionYBottomRight - unionYTopLeft;

    return Rectangle(unionXTopLeft, unionYTopLeft, unionWidth, unionHeight);
}