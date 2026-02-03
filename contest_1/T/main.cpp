#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    std::cout << "\t";
    for (int i = 1; i < n + 1; ++i) {
        if (i == n) {
            std::cout << i << "\n";
        } else {
            std::cout << i << "\t";
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            if (j == n) {
                std::cout << i + j << "\n";
            } else {
                std::cout << i + j << "\t";
            }
        }
    }

    return 0;
}
