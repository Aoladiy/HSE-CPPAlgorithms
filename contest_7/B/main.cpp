#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<int> p(n);
    vector<long long> c(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    vector dp(n + 1, vector<long long>(w + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= p[i - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - p[i - 1]] + c[i - 1]);
        }
    }

    vector<int> chosen_idx;
    int rem = w;
    for (int i = n; i >= 1; i--) {
        if (dp[i][rem] != dp[i - 1][rem]) {
            chosen_idx.push_back(i - 1);
            rem -= p[i - 1];
        }
    }

    const long long total_cost = dp[n][w];
    const int total_weight = w - rem;
    const int m = static_cast<int>(chosen_idx.size());

    cout << total_cost << "\n";
    cout << total_weight << "\n";
    cout << m << "\n";

    for (const int idx: chosen_idx) cout << p[idx] << " ";
    cout << "\n";
    for (const int idx: chosen_idx) cout << c[idx] << " ";
    cout << "\n";

    return 0;
}
