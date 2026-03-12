#include <iostream>
#include <vector>
using namespace std;

int main() {
    int col, row;
    cin >> col >> row;

    vector dp(9, vector<long long>(9, 0));

    for (int c = 1; c <= 8; c++)
        dp[8][c] = 1;

    for (int r = 7; r >= 1; r--) {
        for (int c = 1; c <= 8; c++) {
            if (c - 1 >= 1) dp[r][c] += dp[r + 1][c - 1];
            if (c + 1 <= 8) dp[r][c] += dp[r + 1][c + 1];
        }
    }

    cout << dp[row][col] << "\n";
    return 0;
}
