#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
public:
    explicit FenwickTree(const int n) : n_(n), tree_(n + 1, 0) {
    }

    void update(int i, const long long delta) {
        for (; i <= n_; i += i & (-i)) {
            tree_[i] += delta;
        }
    }

    [[nodiscard]] long long prefixSum(int i) const {
        long long sum = 0;
        for (; i > 0; i -= i & (-i)) {
            sum += tree_[i];
        }
        return sum;
    }

    [[nodiscard]] long long rangeSum(int l, int r) const {
        return prefixSum(r) - prefixSum(l - 1);
    }

private:
    int n_;
    vector<long long> tree_;
};

int main() {
    int n;
    cin >> n;

    vector<long long> a(n + 1, 0);
    FenwickTree fenwick(n);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        fenwick.update(i, a[i]);
    }

    int m;
    cin >> m;

    vector<long long> results;
    for (int q = 0; q < m; ++q) {
        char type;
        cin >> type;

        if (type == 's') {
            int l, r;
            cin >> l >> r;
            results.push_back(fenwick.rangeSum(l, r));
        } else {
            int idx;
            long long value;
            cin >> idx >> value;
            long long delta = value - a[idx];
            a[idx] = value;
            fenwick.update(idx, delta);
        }
    }

    for (size_t i = 0; i < results.size(); ++i) {
        cout << results[i];
        if (i + 1 < results.size()) cout << ' ';
    }
    cout << '\n';

    return 0;
}
