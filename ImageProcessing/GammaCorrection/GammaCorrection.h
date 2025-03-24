#ifndef IMAGE_PROCESSING_IN_C__GAMMACORRECTION_H
#define IMAGE_PROCESSING_IN_C__GAMMACORRECTION_H

#include "../ImageProcessing.h"

class GammaCorrection : public ImageProcessing {
private:
    double gamma;
public:
    GammaCorrection();

    GammaCorrection(double gamma);

    void process(const Image& source, Image& destination) override;
};


#endif
