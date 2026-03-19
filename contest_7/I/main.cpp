#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    const int n = static_cast<int>(s1.size()), m = static_cast<int>(s2.size());

    vector dp(n + 1, vector(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = (s1[i - 1] == s2[j - 1])
                           ? dp[i - 1][j - 1] + 1
                           : max(dp[i - 1][j], dp[i][j - 1]);

    vector<int> idx1, idx2;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            idx1.push_back(i);
            idx2.push_back(j);
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    ranges::reverse(idx1);
    ranges::reverse(idx2);

    cout << dp[n][m] << "\n";
    for (const int x: idx1) cout << x << " ";
    cout << "\n";
    for (const int x: idx2) cout << x << " ";
    cout << "\n";
    return 0;
}
