#include <fstream>
#include <limits>
#include "Image.h"


//constructors
Image::Image() : m_data(nullptr), m_width(0), m_height(0){}

Image::Image(unsigned int w, unsigned int h) : m_width(w), m_height(h){
    m_data = new unsigned char*[w];

    for(unsigned int i = 0; i < w; ++i){
        m_data[i] = new unsigned char[h];

        for(unsigned int j = 0; j < h; ++j){
            m_data[i][j] = 0;
        }
    }
}

Image::Image(const Image &otherImage) : m_width(otherImage.m_width), m_height(otherImage.m_height) {
    m_data = new unsigned char*[m_width];

    for (unsigned int i = 0; i < m_width; ++i) {
        m_data[i] = new unsigned char[m_height];

        for (unsigned int j = 0; j < m_height; ++j) {
            m_data[i][j] = otherImage.m_data[i][j];
        }
    }
}

//getters and setters
unsigned int Image::getWidth() const {
    return m_width;
}

unsigned int Image::getHeight()const{
    return m_height;
}

Size Image::size()const{
    return Size(m_width, m_height);
}

unsigned char& Image::at(unsigned int x, unsigned int y)const{
    return m_data[x][y];
}

unsigned char& Image::at(Point point)const{
    return m_data[point.getXCoord()][point.getYCoord()];
}

void Image::setPixel(unsigned int x, unsigned int y, unsigned char newValue) {
    m_data[x][y] = newValue;
}

void Image::setPixel(Point point, unsigned char newValue) {
    m_data[point.getXCoord()][point.getYCoord()] = newValue;
}

unsigned char* Image::row(int x)const{
    return m_data[x];
}

bool Image::getROI(Image &roiImg, Rectangle roiRect){
    if(roiRect.getXTopLeft() + roiRect.getWidth() > m_width){
        return false;
    }

    if(roiRect.getYLeftCorner() + roiRect.getHeight() > m_height){
        return false;
    }

    for(unsigned int i = 0; i< roiRect.getWidth(); ++i){
        for(unsigned int j = 0; j < roiRect.getHeight(); ++j){
            roiImg.setPixel(i, j, m_data[roiRect.getXTopLeft() + i][roiRect.getYLeftCorner() + j]);
        }
    }
    return true;
}

bool Image::getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    if(x + width > m_width){
        return false;
    }

    if(y + height > m_height){
        return false;
    }

    for(unsigned int i = 0; i < width; ++i){
        for(unsigned int j = 0; j < height; ++j){
            roiImg.setPixel(i, j, m_data[x + i][y + j]);
        }
    }
    return true;
}


//operators
Image& Image::operator=(const Image &otherImage){
    if(this != &otherImage){
        release();

        m_width = otherImage.m_width;
        m_height = otherImage.m_height;

        m_data = new unsigned char *[m_width];

        for (unsigned int i = 0; i < m_width; ++i) {
            m_data[i] = new unsigned char[m_height];

            for (unsigned int j = 0; j < m_height; ++j) {
                m_data[i][j] = otherImage.m_data[i][j];
            }
        }
    }
    return *this;
}

std::ostream& operator <<(std::ostream& os, const Image& image){
    os <<"P2\n";
    os << "# Simple pgm image example\n";
    os << image.getWidth() << " " << image.getHeight() << "\n";
    os << "255\n";

    for(unsigned int i = 0; i< image.getWidth(); ++i){
        for(unsigned int j = 0; j < image.getHeight(); ++j){
            os << static_cast<unsigned int>(image.at(i, j)) << " ";
        }
        os<< "\n";
    }
    return os;
}

std::istream& operator >>(std::istream& is, Image& image){
    std::string magicNumber;
    is >> magicNumber;

    if(magicNumber != "P2"){
        is.setstate(std::ios::failbit);
        return is;
    }

    char ch = is.peek();

    while(ch == '#' || ch == '\n'){
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ch = is.peek();
    }

    unsigned int width, height;
    is >> width >> height;
    image = Image(width, height);

    unsigned int maxPixelValue;
    is >> maxPixelValue;
    is.ignore();

    for(unsigned int i = 0; i < width; ++i){
        for(unsigned int j = 0; j < height; ++j){
            unsigned int pixelValue;
            is >> pixelValue;
            image.setPixel(i, j, static_cast<unsigned char>(pixelValue));
        }
    }
    return is;
}


Image::~Image(){
    release();
}

void Image::release() {
    if(m_data){
        for(unsigned int i = 0; i < m_height; ++i)
            delete[] m_data[i];

        delete[] m_data;
        m_data = nullptr;
    }
}


bool Image::load(std::string imagePath){
    std::ifstream file(imagePath);

    if(!file.is_open()){
        return false;
    }

    if(!(file >> *this)){
        return false;
    }

    file.close();
    return true;
}

bool Image::save(std::string imagePath)const{
    std::ofstream file(imagePath);

    if(!file.is_open()){
        return false;
    }

    file << *this;
    file.close();
    return true;
}


Image Image::operator+(const Image &otherImage) const {
    if(this-> m_width != otherImage.getWidth() || this->m_height != otherImage.getHeight()){
        throw std::invalid_argument("The images do not have the same resolution!");
    }

    Image newImage = Image(m_width, m_height);

    for(unsigned int i = 0; i < m_width; ++i){
        for(unsigned int j = 0; j < m_height; ++j){
            newImage.setPixel(i, j, static_cast<unsigned char>(std::min((int)m_data[i][j] + otherImage.at(i,j), 255)));
        }
    }
    return newImage;
}

Image Image::operator -(const Image &otherImage)const{
    if(this->m_width != otherImage.getWidth() || this->m_height != otherImage.getHeight()){
        throw std::invalid_argument("The images do not have the same resolution!");
    }

    Image newImage = Image(m_width, m_height);

    for(unsigned int i = 0; i < m_width; ++i){
        for(unsigned int j = 0; j < m_height; ++j){
            newImage.setPixel(i, j, static_cast<unsigned char>(std::min((int)m_data[i][j] - otherImage.at(i,j), 0)));
        }
    }
    return newImage;
}

Image Image::operator*(double s)const{
    Image newImage = Image(m_width, m_height);

    for(unsigned int i = 0; i < m_width; ++i){
        for(unsigned int j = 0; j < m_height; ++j){
            newImage.setPixel(i, j, static_cast<unsigned char>(std::min(int(s * m_data[i][j]), 255)));
        }
    }
    return newImage;
}


bool Image::isEmpty() const{
    return m_data == nullptr && m_width == 0 && m_height == 0;
}


Image Image::zeros(unsigned int width, unsigned int height){
    return Image(width, height);
}

Image Image::ones(unsigned int width, unsigned int height){
    Image image = Image(width, height);
    for(unsigned int i = 0; i < width; ++i){
        for(unsigned int j = 0; j< height; ++j){
            image.setPixel(i, j, 1);
        }
    }
    return image;
}


