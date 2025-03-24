
#ifndef IMAGE_PROCESSING_IN_C_SIZE_H
#define IMAGE_PROCESSING_IN_C_SIZE_H


class Size {
private:
    unsigned int width;
    unsigned int height;
public:
    Size();

    Size(unsigned int width, unsigned int height);

    unsigned int getWidth() const;

    void setWidth(unsigned int width);

    unsigned int getHeight() const;

    void setHeight(unsigned int height);

    unsigned long long getArea()const;

    bool operator==(const Size &other) const;

    bool operator<(const Size &other) const;

    bool operator<=(const Size &other) const;

    bool operator>(const Size &other) const;

    bool operator>=(const Size &other) const;

};


#endif
