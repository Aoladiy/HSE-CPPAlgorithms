#include <bits/stdc++.h>
using namespace std;

int main() {
    int S, N;
    cin >> S >> N;

    vector<int> w(N);
    for (int i = 0; i < N; i++) cin >> w[i];

    vector dp(S + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int j = S; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
        }
    }

    cout << dp[S] << "\n";
    return 0;
}
