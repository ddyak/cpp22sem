#include <utility>
#include <iostream>

template<typename Data>
struct SharedPtr {
    SharedPtr(Data* d) : data(d), counter(new size_t(1)) {}

    SharedPtr(const SharedPtr& sh) {
        if (&sh == this) {
            return;
        }
        this->data = sh.data;
        this->counter = sh.counter;
        (*counter)++;
        std::cout << "counter++ " << *(this->counter) << std::endl;
    }

    SharedPtr& operator=(const SharedPtr& sh) {
        if (&sh == this) {
            return *this;
        }
        auto tmp(sh);
        std::swap(*this, sh);
        return *this;
    }

    ~SharedPtr() {
        --(*counter);
        std::cout << "counter-- " << *counter << std::endl;
        if (!counter) {
            delete counter;
            delete data;
        }
    }

    Data& operator*() {
        return *data;
    }


    size_t* counter;
    Data* data;

private:
    SharedPtr() = delete;

};

int main() {
    SharedPtr<int> a(new int);
    auto b = a;

    return 0;
}
