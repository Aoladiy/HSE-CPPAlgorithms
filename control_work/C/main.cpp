#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (j == 0) {
                std::cout << std::abs(i - j);
            } else {
                std::cout << " " << std::abs(i - j);
            }
        }
        if (i != n - 1) {
            std::cout << "\n";
        }
    }

    return 0;
}
