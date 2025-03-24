#include "GammaCorrection.h"
#include <math.h>
#include <iostream>

//constructors
GammaCorrection::GammaCorrection() {
    this->gamma = 1;
}

GammaCorrection::GammaCorrection(double gamma) {
    this->gamma = gamma;
}

//
void GammaCorrection::process(const Image &source, Image &destination) {
    if(destination.getWidth() != source.getWidth() || destination.getHeight() != source.getHeight()){
        destination = Image(source.getWidth(), source.getHeight());
    }

    for(unsigned int i = 0; i < source.getWidth(); ++i){
        for(unsigned int j = 0; j < source.getHeight(); ++j){
            destination.setPixel(i, j, static_cast<unsigned  char>(std::min((int)pow(source.at(i, j), this->gamma), 255)));
        }
    }
}


