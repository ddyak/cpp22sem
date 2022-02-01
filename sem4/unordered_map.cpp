#include <unordered_set>
#include <iostream>
#include <functional>
// Hash
// operator==

struct Hash {
    std::size_t operator()(const std::string& str) const {
        std::size_t hash = 0;
        std::hash<char> hasher;
        for (const auto& k : str) {
            hash += hasher(std::tolower(k));
        }
        return hash;
    }
};

struct EqualTo {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        return std::equal(lhs.begin(), lhs.end(), rhs.begin(), [](char l, char r){
            return std::tolower(l) == std::tolower(r);
        });
    }
};

int main() {
    std::unordered_set<std::string> us = {
        "Search", "search", "sEArch"
    }; // O(1)

    for (const auto& k : us) {
        std::cout << k << std::endl;
    }

    std::unordered_set<std::string, Hash> us_custom = {
        "Search", "search", "sEArch"
    }; // O(1)

    for (const auto& k : us_custom) {
        std::cout << k << std::endl;
    }

    std::cout << EqualTo()("Foo", "foo") << std::endl;
    std::cout << EqualTo()("aBo", "foo") << std::endl;

    return 0;
}
