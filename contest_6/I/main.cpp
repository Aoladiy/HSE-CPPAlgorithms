#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    int S;
    cin >> S;

    constexpr int INF = 1e9;
    vector dp(S + 1, INF);
    vector last(S + 1, -1);
    dp[0] = 0;

    for (int s = 1; s <= S; s++) {
        for (const int c: coins) {
            if (c <= s && dp[s - c] + 1 < dp[s]) {
                dp[s] = dp[s - c] + 1;
                last[s] = c;
            }
        }
    }

    if (dp[S] == INF) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> result;
    int cur = S;
    while (cur > 0) {
        result.push_back(last[cur]);
        cur -= last[cur];
    }

    cout << dp[S] << "\n";
    for (const int x: result) cout << x << " ";
    cout << "\n";

    return 0;
}
