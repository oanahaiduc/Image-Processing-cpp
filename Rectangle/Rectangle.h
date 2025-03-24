#ifndef IMAGE_PROCESSING_IN_C__RECTANGLE_H
#define IMAGE_PROCESSING_IN_C__RECTANGLE_H

#include "Point/Point.h"


class Rectangle {
private:
    int xTopLeft;
    int yTopLeft;
    unsigned int width;
    unsigned int height;

public:
    Rectangle();

    Rectangle(int xTopLeft, int yLeftCorner, unsigned int width, unsigned int height);

    int getXTopLeft() const;

    void setXTopLeft(int xTopLeft);

    int getYLeftCorner() const;

    void setYLeftCorner(int yLeftCorner);

    unsigned int getWidth() const;

    void setWidth(int width);

    unsigned int getHeight() const;

    void setHeight(int height);

    Rectangle operator+ (const Point &translationPoint) const;

    Rectangle operator-(const Point &translationPoint) const;

    Rectangle operator&(const Rectangle &otherRectangle) const;

    Rectangle operator|(const Rectangle &otherRectangle) const;
};


#endif
