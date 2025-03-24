#include <valarray>
#include "ImageProcessing/GammaCorrection/GammaCorrection.h"

void testGammaDefaultConstructor() {
    Image input(2, 2);
    input.setPixel(0, 0, 100);
    input.setPixel(0, 1, 150);
    input.setPixel(1, 0, 200);
    input.setPixel(1, 1, 250);

    Image output;
    GammaCorrection gammaCorrection; // gamma = 1

    gammaCorrection.process(input, output);

    for (unsigned int i = 0; i < 2; ++i)
        for (unsigned int j = 0; j < 2; ++j)
            assert(output.at(i, j) == input.at(i, j));
}

void testGammaCustomPower() {
    Image input(1, 1);
    input.setPixel(0, 0, 100);

    Image output;
    GammaCorrection gamma(2.0);
    gamma.process(input, output);

    int result = static_cast<int>(std::pow(100, 2.0));
    result = std::min(result, 255);
    assert(output.at(0, 0) == static_cast<unsigned char>(result));
}

void testGammaClamp() {
    Image input(1, 1);
    input.setPixel(0, 0, 200);

    Image output;
    GammaCorrection gamma(2.5);
    gamma.process(input, output);

    assert(output.at(0, 0) == 255);
}

void testGammaZeroPixel() {
    Image input(1, 1);
    input.setPixel(0, 0, 0);

    Image output;
    GammaCorrection gamma(0.5);
    gamma.process(input, output);

    assert(output.at(0, 0) == 0);
}

void testGammaAutoResize() {
    Image input(2, 2);
    input.setPixel(0, 0, 10);
    input.setPixel(0, 1, 20);
    input.setPixel(1, 0, 30);
    input.setPixel(1, 1, 40);

    Image wrongSize(1, 1); // not matching source size
    GammaCorrection gamma(1.0);
    gamma.process(input, wrongSize);

    assert(wrongSize.getWidth() == 2);
    assert(wrongSize.getHeight() == 2);
}

void testTest() {
    Image img;
    assert(img.load("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/baboon.ascii.pgm"));

    GammaCorrection processor(0.9);
    Image dst;
    processor.process(img, dst);

    assert(dst.save("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/newAssets/gamma_correction.ascii.pgm"));
}


void runAllGammaCorrectionTests() {
    testGammaDefaultConstructor();
    testGammaCustomPower();
    testGammaClamp();
    testGammaZeroPixel();
    testGammaAutoResize();
    testTest();
}

