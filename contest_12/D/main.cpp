#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class LazyMaxSegmentTree {
public:
    explicit LazyMaxSegmentTree(const int n) : n_(n), tree_(4 * n, 0), lazy_(4 * n, 0) {
    }

    void build(const vector<long long> &a) {
        build(1, 1, n_, a);
    }

    void update(const int l, const int r, const long long val) {
        update(1, 1, n_, l, r, val);
    }

    long long query(const int l, const int r) {
        return query(1, 1, n_, l, r);
    }

private:
    int n_;
    vector<long long> tree_;
    vector<long long> lazy_;

    void build(const int node, const int l, const int r, const vector<long long> &a) {
        if (l == r) {
            tree_[node] = a[l];
            return;
        }
        const int mid = (l + r) / 2;
        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);
        tree_[node] = max(tree_[2 * node], tree_[2 * node + 1]);
    }

    void applyLazy(const int node, const long long val) {
        tree_[node] += val;
        lazy_[node] += val;
    }

    void push_down(const int node) {
        if (lazy_[node] != 0) {
            applyLazy(2 * node, lazy_[node]);
            applyLazy(2 * node + 1, lazy_[node]);
            lazy_[node] = 0;
        }
    }

    void update(const int node, const int l, const int r, const int ql, const int qr, const long long val) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            applyLazy(node, val);
            return;
        }
        push_down(node);
        const int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        tree_[node] = max(tree_[2 * node], tree_[2 * node + 1]);
    }

    long long query(const int node, const int l, const int r, const int ql, const int qr) {
        if (qr < l || r < ql) return LLONG_MIN;
        if (ql <= l && r <= qr) return tree_[node];
        push_down(node);
        const int mid = (l + r) / 2;
        const long long leftResult = query(2 * node, l, mid, ql, qr);
        const long long rightResult = query(2 * node + 1, mid + 1, r, ql, qr);
        return max(leftResult, rightResult);
    }
};

int main() {
    int n;
    cin >> n;

    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    LazyMaxSegmentTree tree(n);
    tree.build(a);

    int q;
    cin >> q;

    vector<long long> results;
    for (int i = 0; i < q; ++i) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            long long x;
            cin >> x;
            tree.update(l, r, x);
        } else {
            results.push_back(tree.query(l, r));
        }
    }

    for (const long long res: results) {
        cout << res << '\n';
    }

    return 0;
}
