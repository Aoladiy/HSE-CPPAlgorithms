#include <iostream>


long long gcd_ext(const long long a, const long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    const long long g = gcd_ext(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b, c;
        std::cin >> a >> b >> c;
        long long x0, y0;
        const long long g = gcd_ext(a, b, x0, y0);
        if (c % g != 0) {
            std::cout << "0 0\n";
            continue;
        }
        const long long mult = c / g;
        x0 *= mult;
        y0 *= mult;
        const long long step = b / g;
        if (x0 >= 0) {
            const long long tv = x0 / step;
            x0 -= tv * step;
            y0 += tv * (a / g);
        } else {
            const long long tv = (-x0 + step - 1) / step;
            x0 += tv * step;
            y0 -= tv * (a / g);
        }
        std::cout << x0 << " " << y0 << "\n";
    }
}
