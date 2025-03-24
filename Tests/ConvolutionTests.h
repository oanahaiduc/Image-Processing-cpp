#include "ImageProcessing/Convolution/Convolution.h"

void testIdentityKernelWithClip() {
    std::vector<std::vector<int>> kernel = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };

    Image input(3, 3);
    input.setPixel(1, 1, 123);

    Image output;
    Convolution conv(kernel, Convolution::clip);
    conv.process(input, output);

    assert(output.at(1, 1) == 123);
}

void testBlurFunction() {
    std::vector<std::vector<int>> kernel = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}
    };

    Image input(3, 3);
    for (unsigned int i = 0; i < 3; ++i)
        for (unsigned int j = 0; j < 3; ++j)
            input.setPixel(i, j, 9);

    Image output;
    Convolution conv(kernel, Convolution::blur);
    conv.process(input, output);

    assert(output.at(1, 1) == 9); // blur works
}

void testGaussianBlurFunction() {
    std::vector<std::vector<int>> kernel = {
            {1, 2, 1},
            {2, 4, 2},
            {1, 2, 1}
    };

    Image input(3, 3);
    for (unsigned int i = 0; i < 3; ++i)
        for (unsigned int j = 0; j < 3; ++j)
            input.setPixel(i, j, 16);

    Image output;
    Convolution conv(kernel, Convolution::gaussianBlur);
    conv.process(input, output);

    assert(output.at(1, 1) == 16);
}

void testAutoResizeDestination() {
    std::vector<std::vector<int>> kernel = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };

    Image input(5, 5);
    input.setPixel(2, 2, 77);

    Image dest(1, 1); // wrong size
    Convolution conv(kernel, Convolution::clip);
    conv.process(input, dest);

    assert(dest.getWidth() == 5);
    assert(dest.getHeight() == 5);
    assert(dest.at(2, 2) == 77);
}

void testThrowsOnEvenKernelSize() {
    std::vector<std::vector<int>> badKernel = {
            {1, 1},
            {1, 1}
    };

    bool exceptionThrown = false;
    try {
        Convolution conv(badKernel, Convolution::clip);
        Image dummy(4, 4);
        Image dest;
        conv.process(dummy, dest);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);
}

void lastTest(){
    Image img;
    img.load("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/baboon.ascii.pgm");

    vector<vector<int>> noopKernel = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };

    vector<vector<int>> horizontalKernel = {
            {1, 2, 1},
            {0, 0, 0},
            {-1, -2, -1}
    };

    vector<vector<int>> verticalKernel = {
            {-1, 0, 1},
            {-2, 0, 2},
            {-1, 0, 1}
    };

    Convolution noopProcessor = Convolution(noopKernel, Convolution::clip);
    Convolution horizProcessor = Convolution(horizontalKernel, Convolution::clip);
    Convolution verticalProcessor = Convolution(verticalKernel, Convolution::clip);

    Image noopImg;
    Image horizImg;
    Image verticalImg;

    noopProcessor.process(img, noopImg);
    horizProcessor.process(img, horizImg);
    verticalProcessor.process(img, verticalImg);

    noopImg.save("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/newAssets/noop_convolution.ascii.pgm");
    horizImg.save("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/newAssets//horizontal_convolution.ascii.pgm");
    verticalImg.save("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/newAssets/vertical_convolution.ascii.pgm");
}

void runAllConvolutionTests() {
    testIdentityKernelWithClip();
    testBlurFunction();
    testGaussianBlurFunction();
    testAutoResizeDestination();
    testThrowsOnEvenKernelSize();
    lastTest();
}

