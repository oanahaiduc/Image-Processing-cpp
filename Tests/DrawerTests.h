#include "DrawingModule/Drawer.h"

void drawerTest(){
    Image circle_image;
    Image line_image;
    Image rect_image1;
    Image rect_image2;

    circle_image.load("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/baboon.ascii.pgm");
    line_image.load("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/baboon.ascii.pgm");
    rect_image1.load("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/baboon.ascii.pgm");
    rect_image2.load("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/baboon.ascii.pgm");

    Drawer::drawCircle(circle_image, Point(256, 256), 64, 1);
    Drawer::drawLine(line_image, Point(20, 20), Point(256, 256), 1);
    Drawer::drawRectangle(rect_image1, Rectangle(128, 128, 100, 64), 1);
    Drawer::drawRectangle(rect_image2, Point(128, 128), Point(192, 230), 1);

    circle_image.save("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/newAssets/new_circle_image.ascii.pgm");
    line_image.save("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/newAssets/new_line_image.ascii.pgm");
    rect_image1.save("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/newAssets/new_rect_image1.ascii.pgm");
    rect_image2.save("C:/Users/Lenovo/CLionProjects/Image-Processing-in-C-/assets/newAssets/new_rect_image2.ascii.pgm");
}