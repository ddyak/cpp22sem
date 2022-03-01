#include <utility>
#include <algorithm>
#include <vector>
#include <initializer_list>

template<typename IteratorA, typename IteratorB>
struct ZipIterator {
    ZipIterator(IteratorA it1, IteratorB it2) : it1(it1), it2(it2) {}
    IteratorA it1;
    IteratorB it2;

    using ValueA = typename std::iterator_traits<IteratorA>::value_type;
    using ValueB = typename std::iterator_traits<IteratorB>::value_type;
    using ZippedPair = std::pair<const ValueA&, const ValueB&>;

    ZippedPair operator*() const {
        return ZippedPair(*it1, *it2);
    }

};

template <typename S1, typename S2>
auto Zipper(const S1& s1, const S2& s2) {
    return ZipIterator(std::begin(s1), std::begin(s2));
}

int main() {
    int a[] = {1, 2, 3};
    auto it = Zipper<int[3], int[3]>(a, a);
    *it;
    return 0;
}
