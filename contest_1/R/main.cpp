#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long N, K;
    std::cin >> N >> K;

    std::vector<long long> B(N);
    for (long long i = 0; i < N; ++i) {
        std::cin >> B[i];
    }
    const long long max = *std::ranges::max_element(B);
    const long long min = *std::ranges::min_element(B);
    std::cout << max - min;

    return 0;
}
