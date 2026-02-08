#include <iostream>
#include <vector>

void print(const size_t n) {
    std::cout << "Size: " << n;
}

void print(const std::vector<int> &v) {
    std::cout << "Vector:\n";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "Value \"" << v[i] << "\" at index " << i << '\n';
    }
}
