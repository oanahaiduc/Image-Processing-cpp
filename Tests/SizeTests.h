#include <iostream>
#include "Size/Size.h"
#include <cassert>

void testConstructor(){
    Size size1;
    assert(size1.getHeight() == 0);
    assert(size1.getWidth() == 0);

    Size size2(14, 155);
    assert(size2.getWidth() == 14);
    assert(size2.getHeight() == 155);
}

void testSetters(){
    Size size1;
    size1.setHeight(40);
    assert(size1.getHeight() == 40);

    size1.setWidth(20);
    assert(size1.getWidth() == 20);
}


void testGetArea(){
    Size size1(10, 10);
    assert(size1.getArea() == 100);
}

void testOperators(){
    Size size1(5, 6);
    Size size2(5, 6);
    Size size3(10, 7);
    Size size4(9, 11);

    assert(size1 == size2);
    assert(size3 > size2);
    assert(size4 >= size3);
    assert(size1 <= size2);
    assert(size1 < size4);
}

void runAllSizeTests() {
    testConstructor();
    testSetters();
    testGetArea();
    testOperators();
}

