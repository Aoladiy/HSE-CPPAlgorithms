#include <iostream>
#include <vector>
using namespace std;

struct Node {
    long long key;
    int left, right;
};

int n;
vector<Node> tree;
vector<long long> subtree_sum;

long long dfs(const int v) {
    if (v == -1) return 0;
    const long long s = tree[v].key + dfs(tree[v].left) + dfs(tree[v].right);
    subtree_sum[v] = s;
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    tree.resize(n);
    subtree_sum.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> tree[i].key >> tree[i].left >> tree[i].right;
    }

    dfs(0);

    for (int i = 0; i < n; i++) {
        cout << subtree_sum[i];
        if (i < n - 1) cout << ' ';
    }
    cout << '\n';

    return 0;
}
