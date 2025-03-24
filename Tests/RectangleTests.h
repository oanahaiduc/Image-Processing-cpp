#include "../Rectangle/Rectangle.h"


void testRectangleDefaultConstructor() {
    Rectangle rect;
    assert(rect.getXTopLeft() == 0);
    assert(rect.getYLeftCorner() == 0);
    assert(rect.getWidth() == 0);
    assert(rect.getHeight() == 0);
}

void testRectangleParameterizedConstructor() {
    Rectangle rect(5, 10, 20, 30);
    assert(rect.getXTopLeft() == 5);
    assert(rect.getYLeftCorner() == 10);
    assert(rect.getWidth() == 20);
    assert(rect.getHeight() == 30);
}

void testRectangleSettersAndGetters() {
    Rectangle rect;
    rect.setXTopLeft(2);
    rect.setYLeftCorner(4);
    rect.setWidth(10);
    rect.setHeight(15);

    assert(rect.getXTopLeft() == 2);
    assert(rect.getYLeftCorner() == 4);
    assert(rect.getWidth() == 10);
    assert(rect.getHeight() == 15);
}

void testRectangleTranslation() {
    Rectangle rect(10, 20, 30, 40);
    Point p(5, 5);

    Rectangle movedPlus = rect + p;
    assert(movedPlus.getXTopLeft() == 15);
    assert(movedPlus.getYLeftCorner() == 25);
    assert(movedPlus.getWidth() == 30);
    assert(movedPlus.getHeight() == 40);

    Rectangle movedMinus = rect - p;
    assert(movedMinus.getXTopLeft() == 5);
    assert(movedMinus.getYLeftCorner() == 15);
    assert(movedMinus.getWidth() == 30);
    assert(movedMinus.getHeight() == 40);
}

void testRectangleIntersection() {
    Rectangle r1(0, 0, 10, 10);
    Rectangle r2(5, 5, 10, 10);

    Rectangle intersect = r1 & r2;

    assert(intersect.getXTopLeft() == 5);
    assert(intersect.getYLeftCorner() == 5);
    assert(intersect.getWidth() == 5);
    assert(intersect.getHeight() == 5);
}

void testRectangleUnion() {
    Rectangle r1(0, 0, 10, 10);
    Rectangle r2(5, 5, 10, 10);

    Rectangle unionRect = r1 | r2;

    assert(unionRect.getXTopLeft() == 0);
    assert(unionRect.getYLeftCorner() == 0);
    assert(unionRect.getWidth() == 15);
    assert(unionRect.getHeight() == 15);
}


void runAllRectangleTests() {
    testRectangleDefaultConstructor();
    testRectangleParameterizedConstructor();
    testRectangleSettersAndGetters();
    testRectangleTranslation();
    testRectangleIntersection();
    testRectangleUnion();
}


