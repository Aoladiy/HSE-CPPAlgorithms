#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector dp(n, vector<long long>(m, 1));

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    cout << dp[n - 1][m - 1] << "\n";
    return 0;
}
