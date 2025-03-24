#ifndef IMAGE_PROCESSING_IN_C__POINT_H
#define IMAGE_PROCESSING_IN_C__POINT_H


class Point {
private:
    int xCoord;
    int yCoord;

public:
    Point();

    Point(int xCoord, int yCoord);

    int getXCoord() const;

    void setXCoord(int xCoord);

    int getYCoord() const;

    void setYCoord(int yCoord);
};


#endif
