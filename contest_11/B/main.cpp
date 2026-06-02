#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    int ans = n - 1;
    for (int i = 0; i < n / 2; i++) {
        const int r = 2 * i + 2;
        if (const int l = 2 * i + 1; l <= ans && a[i] < a[l]) ans = l - 1;
        if (r <= ans && a[i] < a[r]) ans = r - 1;
    }

    std::cout << ans << "\n";
    return 0;
}
