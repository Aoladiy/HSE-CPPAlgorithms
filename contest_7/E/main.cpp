#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> b(n), e(n), w(n);
    for (int i = 0; i < n; i++) cin >> b[i] >> e[i] >> w[i];

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    ranges::sort(idx, [&](const int a, const int b_) { return e[a] < e[b_]; });

    vector<double> sorted_e(n);
    for (int i = 0; i < n; i++) sorted_e[i] = e[idx[i]];

    vector dp(n + 1, 0.0);

    for (int i = 1; i <= n; i++) {
        const int j = idx[i - 1];
        const double bj = b[j], wj = w[j];

        int lo = 0, hi = i - 1;
        while (lo < hi) {
            if (const int mid = (lo + hi + 1) / 2; sorted_e[mid - 1] <= bj)
                lo = mid;
            else
                hi = mid - 1;
        }
        dp[i] = max(dp[i - 1], dp[lo] + wj);
    }

    cout << fixed << setprecision(4) << dp[n] << "\n";
    return 0;
}
