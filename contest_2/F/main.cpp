#include <iostream>
#include <vector>

int main() {
    long long n;
    std::cin >> n;

    std::vector<std::vector<long long> > a(n, std::vector<long long>(n));

    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (i + j == n - 1) {
                a[i][j] = 1;
            } else if (i + j < n - 1) {
                a[i][j] = 0;
            } else {
                a[i][j] = 2;
            }
        }
    }

    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (j) {
                std::cout << ' ';
            }
            std::cout << a[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}
