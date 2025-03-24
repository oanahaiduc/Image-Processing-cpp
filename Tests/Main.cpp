#include "PointTests.h"
#include "SizeTests.h"
#include "RectangleTests.h"
#include "ImageTests.h"
#include "GammaCorrectionTests.h"
#include "ConvolutionTests.h"
#include "BrightnessAndContrastTests.h"
#include "DrawerTests.h"
#include <iostream>

int main(){
    //size tests
    runAllSizeTests();

    //point tests
    runAllPointTests();

    //rectangle tests
    runAllRectangleTests();

    //image tests
    runAllImageTests();

    //gammaCorrection tests
    runAllGammaCorrectionTests();

    //convolution tests
    runAllConvolutionTests();

    //brightness and contrast tests
    runAllBrightnessAndContrastTests();

    //drawer tests
    drawerTest();

    std::cout << "Tests are done!";

    return 0;
}