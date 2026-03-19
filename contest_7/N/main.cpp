#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;

    if (n <= 2) {
        if (n == 1) {
            cout << 0 << "\n";
            return 0;
        }
        cout << (a[0] == a[1] ? 1 : 0) << "\n";
        return 0;
    }

    vector<int> b;
    b.push_back(a[0]);
    for (int i = 1; i < n; i++)
        if (a[i] != b.back()) b.push_back(a[i]);

    const int m = static_cast<int>(b.size());
    if (m == 1) {
        cout << n - 1 << "\n";
        return 0;
    }

    int lzs = 2;
    int dir = (b[1] > b[0]) ? 1 : -1;
    for (int i = 2; i < m; i++) {
        if (const int newdir = (b[i] > b[i - 1]) ? 1 : -1; newdir != dir) {
            lzs++;
            dir = newdir;
        }
    }

    cout << n - lzs << "\n";
    return 0;
}
