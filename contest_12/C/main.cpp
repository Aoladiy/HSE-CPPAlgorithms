#include <iostream>
#include <vector>

using namespace std;

class MaxSegmentTree {
public:
    explicit MaxSegmentTree(const int n) : n_(n), tree_(4 * n, 0) {
    }

    void build(const vector<int> &a) {
        build(1, 1, n_, a);
    }

    void update(const int pos, const int val) {
        update(1, 1, n_, pos, val);
    }

    [[nodiscard]] int findFirst(const int i, const int x) const {
        if (i > n_) return -1;
        return findFirst(1, 1, n_, i, x);
    }

private:
    int n_;
    vector<int> tree_;

    void build(const int node, const int l, const int r, const vector<int> &a) {
        if (l == r) {
            tree_[node] = a[l];
            return;
        }
        const int mid = (l + r) / 2;
        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);
        tree_[node] = max(tree_[2 * node], tree_[2 * node + 1]);
    }

    void update(const int node, const int l, const int r, const int pos, const int val) {
        if (l == r) {
            tree_[node] = val;
            return;
        }
        if (const int mid = (l + r) / 2; pos <= mid) {
            update(2 * node, l, mid, pos, val);
        } else {
            update(2 * node + 1, mid + 1, r, pos, val);
        }
        tree_[node] = max(tree_[2 * node], tree_[2 * node + 1]);
    }

    [[nodiscard]] int findFirst(const int node, const int l, const int r, const int i, const int x) const {
        if (r < i || tree_[node] < x) return -1;
        if (l == r) return l;

        const int mid = (l + r) / 2;
        if (const int leftResult = findFirst(2 * node, l, mid, i, x); leftResult != -1) return leftResult;
        return findFirst(2 * node + 1, mid + 1, r, i, x);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    MaxSegmentTree tree(n);
    tree.build(a);

    vector<int> results;
    for (int q = 0; q < m; ++q) {
        int type, i, x;
        cin >> type >> i >> x;

        if (type == 0) {
            tree.update(i, x);
        } else {
            results.push_back(tree.findFirst(i, x));
        }
    }

    for (const int r: results) {
        cout << r << '\n';
    }

    return 0;
}
