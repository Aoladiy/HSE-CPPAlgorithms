#include <cmath>
#include <iostream>

int main() {
    int n, a;
    std::cin >> n >> a;

    double x = std::sqrt(1.0 * n * a);

    for (int k = n - 1; k >= 1; --k) {
        x = std::sqrt(1.0 * k * a + x);
    }

    std::cout << x;
    return 0;
}
