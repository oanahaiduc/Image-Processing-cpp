#include "Point/Point.h"
#include <cassert>

void testDefaultConstructor() {
    Point p;
    assert(p.getXCoord() == 0);
    assert(p.getYCoord() == 0);
}

void testParameterizedConstructor() {
    Point p(10, 20);
    assert(p.getXCoord() == 10);
    assert(p.getYCoord() == 20);
}

void testSettersAndGetters() {
    Point p;
    p.setXCoord(5);
    p.setYCoord(15);
    assert(p.getXCoord() == 5);
    assert(p.getYCoord() == 15);
}

void runAllPointTests() {
    testDefaultConstructor();
    testParameterizedConstructor();
    testSettersAndGetters();
}

