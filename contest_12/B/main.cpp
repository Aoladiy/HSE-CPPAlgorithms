#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
public:
    explicit FenwickTree(const int n) : n_(n), tree_(n + 1, 0) {
        log_ = 0;
        while ((1 << (log_ + 1)) <= n_) ++log_;
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

    [[nodiscard]] int findKth(const long long target) const {
        if (target <= 0) return -1;
        int pos = 0;
        long long cur = 0;
        for (int pw = log_; pw >= 0; --pw) {
            if (const int next = pos + (1 << pw); next <= n_ && cur + tree_[next] < target) {
                pos = next;
                cur += tree_[next];
            }
        }
        ++pos;
        if (pos > n_) return -1;
        return pos;
    }

private:
    int n_;
    int log_ = 0;
    vector<long long> tree_;
};

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1, 0);
    FenwickTree fenwick(n);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            fenwick.update(i, 1);
        }
    }

    int m;
    cin >> m;

    vector<long long> results;
    for (int q = 0; q < m; ++q) {
        char type;
        cin >> type;

        if (type == 's') {
            int l, r, k;
            cin >> l >> r >> k;

            const long long before = fenwick.prefixSum(l - 1);

            if (const int idx = fenwick.findKth(before + k); idx == -1 || idx > r) {
                results.push_back(-1);
            } else {
                results.push_back(idx);
            }
        } else {
            int p;
            int v;
            cin >> p >> v;

            const bool wasZero = (a[p] == 0);

            if (const bool isZero = (v == 0); wasZero && !isZero) {
                fenwick.update(p, -1);
            } else if (!wasZero && isZero) {
                fenwick.update(p, 1);
            }

            a[p] = v;
        }
    }

    for (const long long result: results) {
        cout << result << '\n';
    }

    return 0;
}
