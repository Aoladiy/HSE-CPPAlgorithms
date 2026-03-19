#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;

    int m;
    cin >> m;
    vector<int> b(m);
    for (int &x: b) cin >> x;

    vector dp(n + 1, vector(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = (a[i - 1] == b[j - 1])
                           ? dp[i - 1][j - 1] + 1
                           : max(dp[i - 1][j], dp[i][j - 1]);

    cout << dp[n][m] << "\n";
    return 0;
}
