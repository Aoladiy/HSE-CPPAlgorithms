#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> dp(m + 1, 0), ndp(m + 1, 0);
    vector<long long> pre(m + 2, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        const long long cap = a[i];

        for (int r = 0; r < i; r++) {
            int cnt = 0;
            pre[0] = 0;
            for (int j = r; j <= m; j += i, cnt++)
                pre[cnt + 1] = pre[cnt] + dp[j];

            for (int k = 0; k < cnt; k++) {
                const int lo = max(0, static_cast<int>(k - cap));
                const long long val = pre[k + 1] - pre[lo];
                ndp[r + k * i] = static_cast<int>(val % MOD);
            }
        }

        swap(dp, ndp);
        ranges::fill(ndp, 0);
    }

    cout << dp[m] << "\n";
    return 0;
}
