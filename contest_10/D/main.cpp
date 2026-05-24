#include <iostream>
#include <vector>
using namespace std;

struct Node {
    long long key;
    int left, right;
};

int n;
vector<Node> tree;

bool dfs(const int v, const long long lo, const long long hi) {
    if (v == -1) return true;
    const long long k = tree[v].key;
    if (k < lo || k >= hi) return false;
    return dfs(tree[v].left, lo, k) && dfs(tree[v].right, k, hi);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i].key >> tree[i].left >> tree[i].right;
    }

    constexpr long long LO = -1LL * (1LL << 31) - 1;
    constexpr long long HI = (1LL << 31);
    cout << (dfs(0, LO, HI) ? "CORRECT" : "INCORRECT") << '\n';

    return 0;
}
