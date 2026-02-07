#include <iostream>
#include <vector>

int main() {
    long long n;
    std::cin >> n;

    std::vector<std::vector<long long> > a(n, std::vector<long long>(n));

    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            std::cin >> a[i][j];
        }
    }

    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (a[i][j] != a[j][i]) {
                std::cout << "no";
                return 0;
            }
        }
    }
    std::cout << "yes";
    return 0;
}
