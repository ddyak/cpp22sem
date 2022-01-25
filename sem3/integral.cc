#include <iostream>
#include <iomanip>

double f(double x) {
    return x * x;
}

double Integrate(std::size_t N, double a, double b, double (*f)(double)) {
    double sum = 0;
    const double step = (b - a) / N;
    for (std::size_t i = 0; i < N; ++i) {
        double x_i = a + i * step + step / 2;
        double f_i = f(x_i);
        sum += f_i * step;
    }
    return sum;
}

int main() {
    std::cout << std::fixed << std::setprecision(10) << std::endl;
    std::cout << Integrate(10, 0, 5, f) << std::endl;
    std::cout << Integrate(100, 0, 5, f) << std::endl;
    std::cout << Integrate(1000, 0, 5, f) << std::endl;
    std::cout << Integrate(10000, 0, 5, f) << std::endl;
    return 0;
}
