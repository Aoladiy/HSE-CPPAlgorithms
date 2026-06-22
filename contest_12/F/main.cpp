#include <iostream>
#include <vector>

using namespace std;

constexpr long long MAXV = 1000000000;
constexpr long long MOD = 1000000000;

class DynamicSegmentTree {
public:
    DynamicSegmentTree() {
        left_.push_back(-1);
        right_.push_back(-1);
        sum_.push_back(0);
        root_ = 0;
    }

    void add(const long long pos) {
        add(root_, 0, MAXV, pos);
    }

    long long sum(const long long l, const long long r) {
        if (l > r) return 0;
        return sum(root_, 0, MAXV, l, r);
    }

private:
    vector<int> left_, right_;
    vector<long long> sum_;
    int root_;

    int newNode() {
        left_.push_back(-1);
        right_.push_back(-1);
        sum_.push_back(0);
        return static_cast<int>(sum_.size()) - 1;
    }

    void add(const int node, const long long l, const long long r, const long long pos) {
        if (l == r) {
            sum_[node] = pos;
            return;
        }
        if (const long long mid = (l + r) / 2; pos <= mid) {
            if (left_[node] == -1) left_[node] = newNode();
            add(left_[node], l, mid, pos);
        } else {
            if (right_[node] == -1) right_[node] = newNode();
            add(right_[node], mid + 1, r, pos);
        }
        sum_[node] = sum_[node] == sum_[node]
                         ? (left_[node] != -1 ? sum_[left_[node]] : 0) + (right_[node] != -1 ? sum_[right_[node]] : 0)
                         : 0;
    }

    long long sum(const int node, const long long l, const long long r, const long long ql, const long long qr) {
        if (node == -1 || qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return sum_[node];
        const long long mid = (l + r) / 2;
        return sum(left_[node], l, mid, ql, qr) + sum(right_[node], mid + 1, r, ql, qr);
    }
};

int main() {
    int n;
    cin >> n;

    DynamicSegmentTree tree;
    long long lastAnswer = -1;

    for (int q = 0; q < n; ++q) {
        char op;
        cin >> op;

        if (op == '+') {
            long long i;
            cin >> i;
            if (lastAnswer != -1) {
                i = (i + lastAnswer) % MOD;
            }
            tree.add(i);
            lastAnswer = -1;
        } else {
            long long l, r;
            cin >> l >> r;
            const long long res = tree.sum(l, r);
            cout << res << '\n';
            lastAnswer = res;
        }
    }

    return 0;
}
