#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<long long> a(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    const auto unique_part_end = std::ranges::unique(a).begin();
    a.resize(std::ranges::distance(a.begin(), unique_part_end));
    std::cout << a.size();
    return 0;
}
