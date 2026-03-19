#include <bits/stdc++.h>
using namespace std;

int main() {
    long long l;
    int n;
    cin >> l >> n;

    vector<long long> c(n + 2);
    c[0] = 0;
    for (int i = 1; i <= n; i++) cin >> c[i];
    c[n + 1] = l;

    const int m = n + 2;

    vector dp(m, vector<long long>(m, 0));

    for (int len = 2; len < m; len++) {
        for (int i = 0; i + len < m; i++) {
            const int j = i + len;
            dp[i][j] = LLONG_MAX;
            const long long piece = c[j] - c[i];
            for (int k = i + 1; k < j; k++) {
                long long cost = piece + dp[i][k] + dp[k][j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[0][m - 1] << "\n";
    return 0;
}
