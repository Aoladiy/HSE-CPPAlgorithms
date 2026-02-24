#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int &x: a) {
        std::cin >> x;
    }

    std::ranges::sort(a);

    int k;
    std::cin >> k;

    for (int i = 0; i < k; ++i) {
        int l, r;
        std::cin >> l >> r;

        auto left = std::ranges::lower_bound(a, l);
        auto right = std::ranges::upper_bound(a, r);

        std::cout << (right - left) << ' ';
    }

    return 0;
}
