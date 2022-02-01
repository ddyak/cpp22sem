#include <iostream>
#include <map>
#include <set>
#include <string_view>
#include <utility>

// Search -> search
// searCH -> search

struct StringViewLessCaseInsensitive {
    bool operator()(std::string_view lhs, std::string_view rhs) const {
        for (std::size_t i = 0; i < lhs.size(); ++i) {
            if (std::tolower(lhs[i]) == std::tolower(rhs[i])) {
                continue;
            }
            return std::tolower(lhs[i]) < std::tolower(rhs[i]);
        }
        return false;
    }
};

//StringViewLessCaseInsensitive a;
//a("asd", "asda"); //== a.operator()("asda", "asda");

int main() {
    std::set<std::string_view> s = {
        "Search", "search", "SeArCh",
    };

    for (const auto& k : s) {
        std::cout << k << std::endl;
    }

    std::set<std::string_view, StringViewLessCaseInsensitive> ss = {
        "Search", "search", "SeArCh",
    };

    for (const auto& k : ss) {
        std::cout << k << std::endl;
    }

    return 0;
}

