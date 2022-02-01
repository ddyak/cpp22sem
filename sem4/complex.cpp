// operator overload
#include <iostream>

struct Complex {
    double re;
    double im;

    Complex(double re=0, double im=0) : re(re), im(im) {}

    Complex operator+(const Complex& rhs) {
        Complex res;
        res.re = re + rhs.re;
        res.im = im + rhs.im;

        return res;
    };

    Complex& operator=(const Complex& comp) {
        if (this == &comp) {
            return *this;
        }

        this->re = comp.re;
        this->im = comp.im;

        return *this;
    }
};

std::ostream &operator<<(std::ostream &os, const Complex &res) {
    os << "Complex: (" << res.re << "+" << res.im << "i)";
    return os;
}

std::istream &operator>>(std::istream &input, Complex &res) {
    input >> res.re >> res.im;
    return input;
}

int main() {
    Complex a(1,0), b(1,1);
    auto c = a + b;

    std::cin >> c;
    std::cout << c << std::endl;

    return 0;
}

