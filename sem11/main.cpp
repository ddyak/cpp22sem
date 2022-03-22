#include <algorithm>
#include <numeric>
#include <thread>
#include <vector>
#include <iostream>

std::atomic<int> result;

void count_thread(const std::vector<int>& arr, size_t left, size_t right, size_t value) {
    mtx.lock();
    for (size_t i = left; i < right; ++i) {
        if (arr[i] == value) {
            result++;
        }
    }
}

int count(const std::vector<int>& arr, size_t val) {
    const size_t cores = 6;

    std::vector<std::thread> threads;
    result = 0;

    size_t part_size = arr.size() / cores;
    for (int i = 0; i < cores; ++i) {
        size_t left = part_size * i;
        size_t right = part_size * (i + 1);
        std::thread th(count_thread, arr, left, right, val);
        threads.push_back(std::move(th));
    }

    for (auto& th : threads) {
        th.join();
    }

    return result;
}

int main() {
    std::vector<int> arr = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    std::cout << count(arr, 1) << std::endl;
    return 0;
}
