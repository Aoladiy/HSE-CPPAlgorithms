#include <bits/stdc++.h>

int main() {
    long long a, k, b, m, x;
    std::cin >> a >> k >> b >> m >> x;

    auto treesD = [&](const long long days) -> long long {
        return (days / k) * (k - 1) * a + std::min(days % k, k - 1) * a;
    };

    auto treesF = [&](const long long days) -> long long {
        return (days / m) * (m - 1) * b + std::min(days % m, m - 1) * b;
    };

    auto canDo = [&](const long long days) -> bool {
        return treesD(days) + treesF(days) >= x;
    };

    long long lo = 1;
    auto hi = static_cast<long long>(2e18 / static_cast<double>(a + b));
    long long best = hi;

    while (lo <= hi) {
        if (const long long mid = lo + (hi - lo) / 2; canDo(mid)) {
            best = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    std::cout << best << '\n';

    return 0;
}
