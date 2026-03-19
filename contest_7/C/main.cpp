#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> m(N), c(N);
    for (int i = 0; i < N; i++) cin >> m[i];
    for (int i = 0; i < N; i++) cin >> c[i];

    vector dp(M + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int j = M; j >= m[i]; j--) {
            dp[j] = max(dp[j], dp[j - m[i]] + c[i]);
        }
    }

    cout << dp[M] << "\n";
    return 0;
}
