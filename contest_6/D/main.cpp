#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cost[101];
    for (int i = 1; i <= n; i++) cin >> cost[i];

    int dp[101] = {};
    dp[1] = cost[1];
    dp[2] = cost[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    cout << dp[n] << endl;
    return 0;
}
