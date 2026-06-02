#include <iostream>
#include <vector>

void siftDown(std::vector<long long> &h, int i, const int size) {
    while (true) {
        int largest = i;
        const int r = 2 * i + 2;
        if (const int l = 2 * i + 1; l < size && h[l] > h[largest]) largest = l;
        if (r < size && h[r] > h[largest]) largest = r;
        if (largest == i) break;
        std::swap(h[i], h[largest]);
        i = largest;
    }
}

void siftUp(std::vector<long long> &h, int i) {
    while (i > 0) {
        const int p = (i - 1) / 2;
        if (h[p] >= h[i]) break;
        std::swap(h[p], h[i]);
        i = p;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n, k;
    std::cin >> n >> k;

    long long a, x, y;
    std::cin >> a >> x >> y;

    constexpr long long MOD = 1LL << 30;

    std::vector<long long> heap;
    heap.reserve(k);

    for (long long i = 0; i < k && i < n; i++) {
        a = (x * a + y) % MOD;
        heap.push_back(a);
        siftUp(heap, static_cast<int>(heap.size()) - 1);
    }

    for (long long i = k; i < n; i++) {
        a = (x * a + y) % MOD;
        if (a < heap[0]) {
            heap[0] = a;
            siftDown(heap, 0, static_cast<int>(k));
        }
    }

    const int sz = static_cast<int>(heap.size());
    for (int i = sz - 1; i > 0; i--) {
        std::swap(heap[0], heap[i]);
        siftDown(heap, 0, i);
    }

    for (int i = 0; i < sz; i++) {
        std::cout << heap[i];
        if (i < sz - 1) std::cout << ' ';
    }
    std::cout << "\n";
    return 0;
}
