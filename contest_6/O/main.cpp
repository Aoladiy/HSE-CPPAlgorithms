#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector dp(n + 1, vector<long long>(n + 1, 0));

    for (int k = 0; k <= n; k++)
        dp[0][k] = 1;

    for (int s = 1; s <= n; s++) {
        for (int k = 1; k <= n; k++) {
            dp[s][k] = dp[s][k - 1];
            if (s >= k)
                dp[s][k] += dp[s - k][k - 1];
        }
    }

    cout << dp[n][n] << "\n";
    return 0;
}
