#include <complex>
#include <iostream>

int main() {
    int n;
    double result = 0;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        switch (i % 2) {
            case 0:
                result -= 1.0 / i;
                break;
            default:
                result += 1.0 / i;
                break;
        }
    }
    std::cout << result;
}
