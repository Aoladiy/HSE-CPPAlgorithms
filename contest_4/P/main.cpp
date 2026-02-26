#include <bits/stdc++.h>

int main() {
    long long n, a, b, w, h;
    std::cin >> n >> a >> b >> w >> h;

    auto canFit = [&](const long long d) {
        const long long moduleA = a + 2 * d;
        const long long moduleB = b + 2 * d;
        const long long cols1 = w / moduleA;
        const long long rows1 = h / moduleB;
        const long long cols2 = w / moduleB;
        const long long rows2 = h / moduleA;
        return cols1 * rows1 >= n || cols2 * rows2 >= n;
    };

    long long lo = 0;
    long long hi = std::min(w, h);
    long long best = 0;

    while (lo <= hi) {
        if (const long long mid = lo + (hi - lo) / 2; canFit(mid)) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::cout << best << '\n';

    return 0;
}
