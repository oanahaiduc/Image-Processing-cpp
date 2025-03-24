#include "Size.h"
Size::Size() : width(0), height(0) {}
Size::Size(unsigned int width, unsigned int height) : width(width), height(height) {}

//getters and setters
unsigned int Size::getWidth() const {
    return width;
}

void Size::setWidth(unsigned int newWidth) {
    this->width = newWidth;
}

unsigned int Size::getHeight() const {
    return height;
}

void Size::setHeight(unsigned int newHeight) {
    this->height = newHeight;
}

unsigned long long Size::getArea() const{
    return static_cast<unsigned long long>(this->width) * static_cast<unsigned long long>(this->height);
}

//operators
bool Size::operator==(const Size &otherSize) const {
    return width == otherSize.width &&
           height == otherSize.height;
}


bool Size::operator<(const Size &otherSize) const {
    return this->getArea() < otherSize.getArea();
}

bool Size::operator<=(const Size &otherSize) const {
    return this->getArea() <= otherSize.getArea();
}

bool Size::operator>(const Size &otherSize) const {
    return this->getArea() > otherSize.getArea();
}

bool Size::operator>=(const Size &otherSize) const {
    return this->getArea() >= otherSize.getArea();

}



