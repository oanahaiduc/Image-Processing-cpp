#ifndef IMAGE_PROCESSING_IN_C__CONVOLUTION_H
#define IMAGE_PROCESSING_IN_C__CONVOLUTION_H

#include "../ImageProcessing.h"
#include <vector>

using std::vector;

typedef int(*ScalingFunction)(int);

class Convolution : public ImageProcessing{
private:
    vector<vector<int>> kernel;
    ScalingFunction scalingFunction;

public:
    static int clip(int value){
        return std::min(std::max(value, 0), 255);
    }

    static int blur(int value){
        return value / 9;
    }

    static int gaussianBlur(int value){
        return value / 16;
    }

    Convolution(const vector<vector<int>>& kernel, ScalingFunction scalingFunction);

    void process(const Image& source, Image& destination) override;

};


#endif
