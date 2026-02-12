#include <iostream>


double FastPow(const double a, const long long n) {
    if (n == 0) {
        return 1.0;
    }

    if (n % 2 == 0) {
        const double half = FastPow(a, n / 2);
        return half * half;
    }
    return a * FastPow(a, n - 1);
}

int main() {
    double a;
    long long n;
    std::cin >> a >> n;

    std::cout << FastPow(a, n);

    return 0;
}
