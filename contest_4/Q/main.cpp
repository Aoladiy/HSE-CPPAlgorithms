#include <bits/stdc++.h>

int main() {
    long long m, n;
    std::cin >> m >> n;

    std::vector<long long> t(n), z(n), y(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i] >> z[i] >> y[i];
    }

    auto balloons = [&](const long long time, const int i) -> long long {
        const long long cycle = z[i] * t[i] + y[i];
        long long count = (time / cycle) * z[i];
        const long long rem = time % cycle;
        count += std::min(rem / t[i], z[i]);
        return count;
    };

    auto canDo = [&](const long long time) -> long long {
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            total += balloons(time, i);
            if (total >= m) { return total; }
        }
        return total;
    };

    long long lo = 0;
    long long hi = 15000LL * 100 * 1000;
    long long best = hi;

    while (lo <= hi) {
        if (const long long mid = lo + (hi - lo) / 2; canDo(mid) >= m) {
            best = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    std::cout << best << '\n';

    long long remaining = m;
    for (int i = 0; i < n; ++i) {
        const long long got = std::min(balloons(best, i), remaining);
        std::cout << got;
        remaining -= got;
        if (i < n - 1) { std::cout << ' '; }
    }
    std::cout << '\n';

    return 0;
}
