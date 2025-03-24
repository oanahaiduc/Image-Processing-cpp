#ifndef IMAGE_PROCESSING_IN_C__IMAGEPROCESSING_H
#define IMAGE_PROCESSING_IN_C__IMAGEPROCESSING_H

#include "../Image/Image.h"

class ImageProcessing{
public:
    virtual void process(const Image& source, Image& destination) = 0;
};

#endif
