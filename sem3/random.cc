#include <iostream>
#include <random>

int pseudo() {
    std::srand(42);
    int a = std::rand(); // 0..10000000
    return a % 10;
}

int main() {
    std::random_device rd; //
    std::mt19937 mt(rd()); // 1237921312
    std::normal_distribution<double> dist(1, 10);

    for (int i = 0; i < 10; ++i) {
        std::cout << dist(mt) << std::endl;
    }

    return 0;
}

