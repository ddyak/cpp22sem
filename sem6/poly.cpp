#include <initializer_list>

class Poly {
publuc:
    Poly() = default;
    Poly(const std::initializer_list<std::pair<int64_t, int64_t>>& il) {
        for (const auto& [pow, coef] : il) {
            if (coef != 0) {
                coef_[pow] = coef;
            }
        }
    }

    Poly(const std::initializer_list<in64_t>& il) {
        size_t pow = 0;
        for (const auto& coef : il) {
            if (coef != 0) {
                coef_[pow] = coef;
            }
            pow++;
        }
    }

    Poly operator+(const Poly& other) const {
        // 2 pointers
    }

private:
    std::map<int64_t, int64_t> coef_;
};
