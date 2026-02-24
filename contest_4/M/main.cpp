#include <bits/stdc++.h>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<long long> a(n);
    for (long long &x: a) {
        std::cin >> x;
    }

    auto canPlace = [&](const long long dist) {
        int placed = 1;
        long long last = a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] - last >= dist) {
                ++placed;
                last = a[i];
            }
        }
        return placed >= k;
    };

    long long lo = 1;
    long long hi = a[n - 1] - a[0];
    long long best = 0;

    while (lo <= hi) {
        if (const long long mid = lo + (hi - lo) / 2; canPlace(mid)) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::cout << best << '\n';

    return 0;
}
