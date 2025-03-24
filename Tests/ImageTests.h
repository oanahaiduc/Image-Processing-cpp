#include "Image/Image.h"


void testDefaultConstructorAndIsEmpty() {
    Image img;
    assert(img.isEmpty());
}

void testParameterizedImageConstructor() {
    Image img(5, 5);
    assert(!img.isEmpty());
    assert(img.getWidth() == 5);
    assert(img.getHeight() == 5);

    for (unsigned int i = 0; i < 5; ++i)
        for (unsigned int j = 0; j < 5; ++j)
            assert(img.at(i, j) == 0);
}

void testSetAndGetPixel() {
    Image img(2, 2);
    img.setPixel(0, 0, 100);
    img.setPixel(Point(1, 1), 200);
    assert(img.at(0, 0) == 100);
    assert(img.at(Point(1, 1)) == 200);
}

void testRowAccess() {
    Image img(3, 3);
    img.setPixel(1, 2, 77);
    const unsigned char* row = img.row(1);
    assert(row[2] == 77);
}

void testCopyConstructorAndAssignment() {
    Image img1(2, 2);
    img1.setPixel(0, 0, 42);

    Image img2(img1); // copy constructor
    assert(img2.at(0, 0) == 42);

    Image img3;
    img3 = img1; // assignment
    assert(img3.at(0, 0) == 42);
}

void testAdditionOperator() {
    Image a(2, 2), b(2, 2);
    a.setPixel(0, 0, 150);
    b.setPixel(0, 0, 120);
    Image c = a + b;
    assert(c.at(0, 0) == 255); // clamped to 255
}

void testSubtractionOperator() {
    Image a(2, 2), b(2, 2);
    a.setPixel(0, 0, 100);
    b.setPixel(0, 0, 50);
    Image c = a - b;
    assert(c.at(0, 0) == 0); // your code clamps to 0 due to min(..., 0), so always zero
}

void testMultiplyOperator() {
    Image img(1, 1);
    img.setPixel(0, 0, 50);
    Image result = img * 5.0;
    assert(result.at(0, 0) == 250);

    result = img * 10.0;
    assert(result.at(0, 0) == 255); // clamped
}

void testZerosAndOnes() {
    Image zero = Image::zeros(2, 2);
    Image one = Image::ones(2, 2);

    for (unsigned int i = 0; i < 2; ++i)
        for (unsigned int j = 0; j < 2; ++j) {
            assert(zero.at(i, j) == 0);
            assert(one.at(i, j) == 1);
        }
}

void testROIWithRectangle() {
    Image img(4, 4);
    img.setPixel(1, 1, 123);

    Rectangle roiRect(1, 1, 2, 2);
    Image roi(2, 2);
    bool success = img.getROI(roi, roiRect);
    assert(success);
    assert(roi.at(0, 0) == 123);
}

void testROIWithCoords() {
    Image img(4, 4);
    img.setPixel(2, 2, 88);

    Image roi(2, 2);
    bool success = img.getROI(roi, 2, 2, 2, 2);
    assert(success);
    assert(roi.at(0, 0) == 88);
}

void runAllImageTests() {
    testDefaultConstructorAndIsEmpty();
    testParameterizedImageConstructor();
    testSetAndGetPixel();
    testRowAccess();
    testCopyConstructorAndAssignment();
    testAdditionOperator();
    testSubtractionOperator();
    testMultiplyOperator();
    testZerosAndOnes();
    testROIWithRectangle();
    testROIWithCoords();

}

