#include <iostream>
#include <vector>
#include <string>

struct MinHeap {
    std::vector<long long> h;

    void siftUp(int i) {
        while (i > 0) {
            const int p = (i - 1) / 2;
            if (h[p] <= h[i]) break;
            std::swap(h[i], h[p]);
            i = p;
        }
    }

    void siftDown(int i) {
        const int n = static_cast<int>(h.size());
        while (true) {
            int smallest = i;
            const int r = 2 * i + 2;
            if (const int l = 2 * i + 1; l < n && h[l] < h[smallest]) smallest = l;
            if (r < n && h[r] < h[smallest]) smallest = r;
            if (smallest == i) break;
            std::swap(h[i], h[smallest]);
            i = smallest;
        }
    }

    void insert(const long long x) {
        h.push_back(x);
        siftUp(static_cast<int>(h.size()) - 1);
    }

    [[nodiscard]] long long getMin() const { return h[0]; }

    long long extractMin() {
        const long long mn = h[0];
        h[0] = h.back();
        h.pop_back();
        if (!h.empty()) siftDown(0);
        return mn;
    }

    void decreaseKey(const long long x, const long long y) {
        for (int i = 0; i < static_cast<int>(h.size()); i++) {
            if (h[i] == x) {
                h[i] = y;
                siftUp(i);
                return;
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q;
    std::cin >> q;

    MinHeap heap;
    std::string op;
    while (q--) {
        std::cin >> op;
        if (op == "insert") {
            long long x;
            std::cin >> x;
            heap.insert(x);
        } else if (op == "extractMin") {
            std::cout << heap.extractMin() << "\n";
        } else if (op == "getMin") {
            std::cout << heap.getMin() << "\n";
        } else {
            long long x, y;
            std::cin >> x >> y;
            heap.decreaseKey(x, y);
        }
    }
    return 0;
}
