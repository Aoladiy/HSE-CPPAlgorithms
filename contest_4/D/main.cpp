#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x: a) {
        std::cin >> x;
    }

    for (int i = 1; i < n; i++) {
        const int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        if (j + 1 != i) {
            for (int k = 0; k < n; k++) {
                std::cout << a[k];
                if (k < n - 1) {
                    std::cout << ' ';
                }
            }
            std::cout << '\n';
        }
    }

    return 0;
}
