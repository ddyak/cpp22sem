#include <iostream>
#include <vector>

// dynamic
class IFilter {
public:
    virtual void Apply() = 0;
};

class Crop : public IFilter {
public:
    void Apply() override {std::cout << "Crop" << std::endl;}
};

class Inverse : public IFilter {
public:
    void Apply() override {std::cout << "Inverse" << std::endl;}
};

// static

template<typename T>
struct Filter {
    void Apply() {
        static_cast<T*>(this)->implementation();
    }
};

class Conv : Filter<Conv> {
    void implementation() {}
};

class Neg : Filter<Neg> {
    void implementation() {}
};

int main() {
    // dynamic
    std::vector<IFilter*> filters;
    filters.push_back(new Crop());
    filters.push_back(new Inverse());
    for (IFilter* filter : filters) {
        filter->Apply();
    }
    return 0;
}

