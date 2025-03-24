#include "BrightnessAndContrast.h"

BrightnessAndContrast::BrightnessAndContrast() {
    this->alpha = 1;
    this->beta = 0;
}

BrightnessAndContrast::BrightnessAndContrast(double alpha, double beta) {
    this->alpha = alpha;
    this->beta =beta;
}

void BrightnessAndContrast::process(const Image &source, Image &destination) {
    destination = source * this->alpha + Image::ones(source.getWidth(), source.getHeight()) * this->beta;
}
