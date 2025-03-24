#ifndef IMAGE_PROCESSING_IN_C__DRAWER_H
#define IMAGE_PROCESSING_IN_C__DRAWER_H

#include "../Point/Point.h"
#include "../Size/Size.h"
#include "../Rectangle/Rectangle.h"
#include "../Image/Image.h"


class Drawer {
private:
    static int squared(int x){
        return x * x;
    }

    static int dist(int x1, int y1, int x2, int y2){
        return squared(x2 - x1) + squared(y2 - y1);
    }

    static bool areCollinear(int x1, int y1, int x2, int y2, int x3, int y3){
        return (x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1);
    }

    static bool isInsideRectangle(int x, int y, int x1, int y1, int x2, int y2){
        return x1 <= x && x <= x2 && y1 <= y && y <= y2;
    }

public:
    static void drawCircle(Image& image, Point center, int radius, unsigned char color){
        for(int i = 0; i < image.getWidth(); ++i){
            for(int j = 0; j < image.getHeight(); ++j){
                if(dist(center.getXCoord(), center.getYCoord(), i, j) <= squared(radius)){
                    image.setPixel(i, j, color);
                }
            }
        }
    }

    static void drawLine(Image& image, Point p1, Point p2, unsigned char color){
        for(int i = 0; i < image.getWidth(); ++i){
            for(int j = 0; j <= image.getHeight(); ++j){
                if(areCollinear(p1.getXCoord(), p1.getYCoord(), p2.getXCoord(), p2.getYCoord(), i, j)){
                    image.setPixel(i, j, color);
                }
            }
        }
    }

    static void drawRectangle(Image& image, Rectangle r, unsigned char color){
        for(int i = 0; i < image.getWidth(); ++i){
            for(int j = 0; j <= image.getHeight(); ++j){
                if(isInsideRectangle(i, j, r.getXTopLeft(), r.getYLeftCorner(), r.getXTopLeft() + r.getWidth() - 1, r.getYLeftCorner() - r.getHeight() - 1)){
                    image.setPixel(i, j, color);
                }
            }
    }
    }

    static void drawRectangle(Image& image, Point p1, Point br, unsigned char color){
        for(int i = 0; i < image.getWidth(); ++i){
            for(int j = 0; j <= image.getHeight(); ++j){
                if(isInsideRectangle(i, j, p1.getXCoord(), p1.getYCoord(), br.getXCoord(), br.getYCoord())){
                    image.setPixel(i, j, color);
                }
            }
        }
    }
};


#endif
