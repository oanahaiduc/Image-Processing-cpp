#ifndef IMAGE_PROCESSING_IN_C__BRIGHTNESSANDCONTRAST_H
#define IMAGE_PROCESSING_IN_C__BRIGHTNESSANDCONTRAST_H

#include "../ImageProcessing.h"

class BrightnessAndContrast : public ImageProcessing {
private:
    double alpha;
    double beta;
public:
    BrightnessAndContrast();

    BrightnessAndContrast(double alpha, double beta);

    void process(const Image& source, Image& destination) override;
};


#endif
