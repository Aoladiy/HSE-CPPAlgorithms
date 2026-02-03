#include <iostream>

int main() {
    long long m1, m2, n1, n2;
    std::cin >> m1 >> m2 >> n1 >> n2;
    for (long long i = m1; i < m2 + 1; ++i) {
        for (long long j = n1; j < n2 + 1; ++j) {
            std::cout << i << " x " << j << " = " << i * j << "\n";
        }
        std::cout << "\n";
    }
    return 0;
}
