#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    vector dp(m, 0);

    for (int i = 0; i < n; i++) {
        int best = 0;
        for (int j = 0; j < m; j++) {
            if (b[j] < a[i])
                best = max(best, dp[j]);
            if (a[i] == b[j])
                dp[j] = max(dp[j], best + 1);
        }
    }

    cout << *ranges::max_element(dp) << "\n";
    return 0;
}
