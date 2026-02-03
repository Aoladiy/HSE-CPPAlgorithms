#include <iostream>

int main() {
    long long N, mn, mx;
    long long sum = 0;
    long long next;

    std::cin >> N;
    if (N <= 0) {
        constexpr long long limit = 1000000000;
        mn = limit;
        mx = -limit;
        std::cout << sum << " " << mn << " " << mx;
        return 0;
    }

    std::cin >> next;
    sum += next;
    mn = next;
    mx = next;

    for (int i = 1; i < N; ++i) {
        std::cin >> next;
        sum += next;
        if (next < mn) {
            mn = next;
        }
        if (next > mx) {
            mx = next;
        }
    }
    std::cout << sum << " " << mn << " " << mx;
    return 0;
}
