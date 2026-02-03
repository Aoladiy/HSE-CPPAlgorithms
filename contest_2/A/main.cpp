#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    long long N;
    std::cin >> N;

    std::vector<long long> B(N);
    for (long long i = 0; i < N; ++i) {
        std::cin >> B[i];
    }
    const long long mx = *std::ranges::max_element(B);
    const long long mn = *std::ranges::min_element(B);
    double avg;
    const long long sum = std::accumulate(B.begin(), B.end(), 0LL);

    if (B.empty()) {
        avg = 0;
    } else {
        avg = static_cast<double>(sum) / static_cast<double>(B.size());
    }

    std::cout << sum << std::fixed << std::setprecision(4) << " " << avg << '\n';

    std::cout << mn << " " << mx;

    return 0;
}
