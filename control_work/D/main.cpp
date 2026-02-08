#include <iostream>
#include <vector>

int main() {
    long long n, m;
    std::cin >> n >> m;

    std::vector<std::vector<long long> > a(n, std::vector<long long>(m));
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }

    long long k;
    std::cin >> k;

    for (long long i = 0; i < n; ++i) {
        long long same = 0;
        for (long long j = 0; j < m; ++j) {
            if (a[i][j] == 0) {
                ++same;
                if (same == k) {
                    std::cout << (i + 1);
                    return 0;
                }
            } else {
                same = 0;
            }
        }
    }

    std::cout << 0;
    return 0;
}
