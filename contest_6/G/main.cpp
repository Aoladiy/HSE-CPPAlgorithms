#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long dp[3] = {1, 1, 1};

    for (int i = 2; i <= n; i++) {
        const long long nextA = dp[1] + dp[2];
        const long long nextB = dp[0] + dp[1] + dp[2];
        const long long nextC = dp[0] + dp[1] + dp[2];
        dp[0] = nextA;
        dp[1] = nextB;
        dp[2] = nextC;
    }

    cout << dp[0] + dp[1] + dp[2] << "\n";
    return 0;
}
