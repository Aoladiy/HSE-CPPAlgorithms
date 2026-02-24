#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x: a) {
        std::cin >> x;
    }

    if (n == 0) {
        std::cout << "\n";
        return 0;
    }

    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[maxIdx]) {
            maxIdx = i;
        }
    }

    std::swap(a[maxIdx], a[n - 1]);

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}
