#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long dp[2] = {1, 1};

    for (int i = 2; i <= n; i++) {
        const long long next0 = dp[0] + dp[1];
        const long long next1 = dp[0];
        dp[0] = next0;
        dp[1] = next1;
    }

    cout << dp[0] + dp[1] << "\n";
    return 0;
}
