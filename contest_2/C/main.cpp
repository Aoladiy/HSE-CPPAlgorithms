#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    long long N;
    std::cin >> N;
    if (N > 0) {
        long long next, previous;
        std::cin >> previous;
        for (int i = 0; i < N - 1; ++i) {
            std::cin >> next;
            if (next > 0 && previous > 0 || next < 0 && previous < 0) {
                std::cout << "YES";
                return 0;
            }
            previous = next;
        }
    }
    std::cout << "NO";
    return 0;
}
