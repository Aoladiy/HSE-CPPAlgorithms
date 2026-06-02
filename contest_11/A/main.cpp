#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    bool isMax = true, isMin = true;
    for (int i = 0; i < n; i++) {
        const int r = 2 * i + 2;
        if (const int l = 2 * i + 1; l < n) {
            if (a[i] < a[l]) isMax = false;
            if (a[i] > a[l]) isMin = false;
        }
        if (r < n) {
            if (a[i] < a[r]) isMax = false;
            if (a[i] > a[r]) isMin = false;
        }
    }

    std::cout << (isMax || isMin ? "YES" : "NO") << "\n";
    return 0;
}
