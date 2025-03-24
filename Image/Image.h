#ifndef IMAGE_PROCESSING_IN_C__IMAGE_H
#define IMAGE_PROCESSING_IN_C__IMAGE_H

#include <string>
#include "Rectangle/Rectangle.h"
#include "Size/Size.h"
#include "Point/Point.h"

class Image {
private:
    unsigned char** m_data;
    unsigned int m_width;
    unsigned int m_height;

public:
    Image();

    Image(unsigned int w, unsigned int h);

    Image(const Image &otherImage);

    Image& operator=(const Image &otherImage);

    ~Image();

    bool load(std::string imagePath);

    bool save(std::string imagePath) const;

    Image operator+(const Image &otherImage)const;

    Image operator-(const Image &otherImage)const;

    Image operator*(double s)const;

    bool getROI(Image &roiImg, Rectangle roiRect);

    bool getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);

    bool isEmpty() const;

    Size size() const;

    unsigned int getWidth() const;

    unsigned int getHeight() const;

    unsigned char& at(unsigned int x, unsigned int y)const;

    unsigned char& at(Point point)const;

    void setPixel(unsigned int x, unsigned int y, unsigned char newValue);

    void setPixel(Point point, unsigned char newValue);

    unsigned char* row(int x) const;

    void release();

    friend std::ostream& operator<<(std::ostream& os, const Image& image);

    friend std::istream& operator>>(std::istream& is, Image& image);

    static Image zeros(unsigned int width, unsigned int height);

    static Image ones(unsigned int width, unsigned int height);
};


#endif
