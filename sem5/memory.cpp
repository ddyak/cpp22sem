#include <iostream>
#include <exception>

template <class T>
class Vector {
    size_t size_ = 0;
    size_t capacity_ = 0;
    T* data_ = nullptr;

void resize_capacity(size_t new_size) {
    T* new_data_ = new T[new_size];

    std::cerr << new_size << std::endl;

    for (int i = 0; i < size_; ++i) {
        new_data_[i] = data_[i];
    }

    delete[] data_;

    data_ = new_data_;
    capacity_ = new_size;
}

public:
    Vector(std::size_t size, const T& value) {
        data_ = new T[size];
        if (!data_) {
            throw std::exception();
        }

        capacity_ = size;
        size_ = size;

        for (size_t i = 0; i < size; ++i) {
            data_[i] = value;
        }
    }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            resize_capacity(size_ * 1.6);
        }
        data_[size_] = value;
        ++size_;
    }

    T& operator[](std::size_t idx) {
        return data_[idx];
    };

    size_t size() {
        return size_;
    }
};


int main() {
//    std::vector<int> vec;
//    vec.resize(10);
    Vector<int> vec(10, 2);
    vec.push_back(5);
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << std::endl;
    }

    return 0;
}
