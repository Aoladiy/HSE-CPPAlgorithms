#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long n, m;
    std::cin >> n >> m;

    long long winner = 0;
    long long best_w = -1;
    long long sum_w = -1;

    for (long long i = 0; i < n; ++i) {
        long long best = -1;
        long long sum = 0;

        for (long long j = 0; j < m; ++j) {
            long long x;
            std::cin >> x;
            best = std::max(best, x);
            sum += x;
        }

        if (best > best_w || (best == best_w && sum > sum_w)) {
            best_w = best;
            sum_w = sum;
            winner = i;
        }
    }

    std::cout << winner;
    return 0;
}
