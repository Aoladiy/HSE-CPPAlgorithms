#include <iostream>

int main() {
    long long n, m;
    std::cin >> n >> m;

    std::cout << "\t";
    for (int i = 1; i < n + 1; ++i) {
        if (i == n) {
            std::cout << i << "\n";
        } else {
            std::cout << i << "\t";
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        std::cout << i << "\t";
        for (int j = 1; j < n + 1; ++j) {
            if (j == n) {
                std::cout << (i * j) % m << "\n";
            } else {
                std::cout << (i * j) % m << "\t";
            }
        }
    }

    return 0;
}
