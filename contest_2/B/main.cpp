#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    long long N;
    long long next;
    long long gtz = 0;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> next;
        if (next > 0) {
            gtz++;
        }
    }
    std::cout << gtz;
    return 0;
}
