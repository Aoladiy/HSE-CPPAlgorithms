#include <bits/stdc++.h>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<long long> a(n);
    for (long long &x: a) {
        std::cin >> x;
    }

    auto canCut = [&](const long long len) {
        long long pieces = 0;
        for (int i = 0; i < n; ++i) {
            pieces += a[i] / len;
        }
        return pieces >= k;
    };

    long long lo = 1;
    long long hi = 10000000;
    long long best = 0;

    while (lo <= hi) {
        if (const long long mid = lo + (hi - lo) / 2; canCut(mid)) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::cout << best << '\n';

    return 0;
}
