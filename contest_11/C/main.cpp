#include <iostream>
#include <vector>

void siftDown(std::vector<long long> &a, int i, const int size) {
    while (true) {
        int largest = i;
        const int r = 2 * i + 2;
        if (const int l = 2 * i + 1; l < size && a[l] > a[largest]) largest = l;
        if (r < size && a[r] > a[largest]) largest = r;
        if (largest == i) break;
        std::swap(a[i], a[largest]);
        i = largest;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    for (int i = n / 2 - 1; i >= 0; i--) siftDown(a, i, n);

    for (int size = n - 1; size > 0; size--) {
        std::swap(a[0], a[size]);
        siftDown(a, 0, size);
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i];
        if (i < n - 1) std::cout << ' ';
    }
    std::cout << "\n";
    return 0;
}
