#include <bits/stdc++.h>

bool binarySearch(const std::vector<int> &a, const int target) {
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;

    while (left <= right) {
        if (const int mid = left + (right - left) / 2; a[mid] == target) {
            return true;
        } else if (a[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int &x: a) {
        std::cin >> x;
    }

    for (int i = 0; i < k; ++i) {
        int q;
        std::cin >> q;
        if (binarySearch(a, q)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
