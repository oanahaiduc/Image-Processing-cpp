#include <stdexcept>
#include "Convolution.h"

using std::vector;

//constructor
Convolution::Convolution(const vector<vector<int>> &kernel, ScalingFunction scalingFunction) {
    this->kernel = kernel;
    this->scalingFunction = scalingFunction;
}

//
void Convolution::process(const Image& source, Image& destination){
    if(kernel.size() % 2 == 0 || kernel[0].size() % 2 == 0){
        throw std::invalid_argument("Kernel dimensions must be an odd number.");
    }

    if(destination.getWidth() != source.getWidth() || destination.getHeight() != source.getHeight()){
        destination = Image(source.getWidth(), source.getHeight());
    }

    int halfKernelHeight = kernel.size() / 2;
    int halfKernelWidth = kernel[0].size() /2;

    for(unsigned int i = halfKernelWidth; i < source.getWidth() - halfKernelWidth; ++i){
        for(unsigned int j = halfKernelHeight; j < source.getHeight() - halfKernelHeight; ++j){
            int newValue = 0;

            for(int ki = -halfKernelHeight; ki <= halfKernelWidth; ++ki){
                for(int kj = -halfKernelHeight; kj <= halfKernelHeight; ++kj){
                    int pixel = source.at(i + ki, j + kj);
                    int kernelValue = kernel[ki + halfKernelWidth][kj + halfKernelHeight];

                    newValue += pixel * kernelValue;
                }
            }
            destination.setPixel(i, j, scalingFunction(newValue));
        }
    }
}