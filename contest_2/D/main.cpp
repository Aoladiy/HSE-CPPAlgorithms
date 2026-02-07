#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    long long N;
    std::cin >> N;
    if (N > 0) {
        std::vector<long long> lst(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> lst[i];
        }
        for (int i = 0; i < N - 1; ++++i) {
            if (i == 0) {
                std::cout << lst[i + 1] << " " << lst[i];
            } else {
                std::cout << " " << lst[i + 1] << " " << lst[i];
            }
        }
        if (N % 2 == 1) {
            std::cout << " " << lst[N - 1];
        }
    }
    return 0;
}
