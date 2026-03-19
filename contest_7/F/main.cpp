#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, rank_;
    explicit DSU(const int n) : p(n), rank_(n, 0) { iota(p.begin(), p.end(), 0); }
    int find(const int x) { return p[x] == x ? x : p[x] = find(p[x]); }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank_[a] < rank_[b]) swap(a, b);
        p[b] = a;
        if (rank_[a] == rank_[b]) rank_[a]++;
        return true;
    }
};

int main() {
    int n;
    cin >> n;

    vector<tuple<long long, int, int> > edges;
    edges.reserve(2 * n - 1);

    for (int i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        edges.emplace_back(a, 0, i);
    }

    for (int i = 1; i < n; i++) {
        long long b;
        cin >> b;
        edges.emplace_back(b, i, i + 1);
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n + 1);
    long long total = 0;

    for (auto &[cost, u, v]: edges) {
        if (dsu.unite(u, v))
            total += cost;
    }

    cout << total << "\n";
    return 0;
}
