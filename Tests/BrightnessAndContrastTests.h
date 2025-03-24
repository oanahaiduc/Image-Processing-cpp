#include "ImageProcessing/BrightnessAndContrast/BrightnessAndContrast.h"

void testDefaultBrightnessAndContrast() {
    Image src(2, 2);
    src.setPixel(0, 0, 100);
    src.setPixel(1, 1, 200);

    Image dst;
    BrightnessAndContrast bc;
    bc.process(src, dst);

    assert(dst.at(0, 0) == 100);
    assert(dst.at(1, 1) == 200);
}

void testBrightnessOnly() {
    Image src(1, 1);
    src.setPixel(0, 0, 50);

    Image dst;
    BrightnessAndContrast bc(1.0, 20);
    bc.process(src, dst);

    assert(dst.at(0, 0) == 70);
}

void testContrastOnly() {
    Image src(1, 1);
    src.setPixel(0, 0, 50);

    Image dst;
    BrightnessAndContrast bc(2.0, 0);
    bc.process(src, dst);

    assert(dst.at(0, 0) == 100);
}

void testBrightnessAndContrastTogether() {
    Image src(1, 1);
    src.setPixel(0, 0, 50);

    Image dst;
    BrightnessAndContrast bc(2.0, 30);
    bc.process(src, dst);

    assert(dst.at(0, 0) == 130);
}

void testClampingTo255() {
    Image src(1, 1);
    src.setPixel(0, 0, 200);

    Image dst;
    BrightnessAndContrast bc(2.0, 100);
    bc.process(src, dst);

    assert(dst.at(0, 0) == 255); // clamped
}

void finalTest(){
    Image img;
    img.load("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/baboon.ascii.pgm");

    BrightnessAndContrast processor = BrightnessAndContrast(1.5, 1.25);

    Image dst;

    processor.process(img, dst);

    dst.save("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/newAssets/brightness_and_contrast.ascii.pgm");

}

void runAllBrightnessAndContrastTests() {
    testDefaultBrightnessAndContrast();
    testBrightnessOnly();
    testContrastOnly();
    testBrightnessAndContrastTogether();
    testClampingTo255();
    finalTest();
}

