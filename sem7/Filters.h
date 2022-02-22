#include "Image.h"

class IFilter {
public:
    virtual void Apply(Image& image) const;
};

class IConvFilter {
public:
    void Apply(Image& image) const override {
        std::vector<std::vector<float>> kernel = GetKernel();
        // for for for for
    }

    virtual std::vector<std::vector<float>> GetKernel() const;
}


class EdgeSegmentationFilter {
public:
    std::vector<std::vector<float>> GetKernel() const override {
        return {{1,2,3}, {4,5,6}, {7,8,9}}
    }
};

class BlurFilter {
public:
    std::vector<std::vector<float>> GetKernel() const override {
        return {{5,1,3}, {2,5,1}, {1,1,1}}
    }
};


