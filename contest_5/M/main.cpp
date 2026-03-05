#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long bestSum = LLONG_MIN, curSum = 0;
    int ansL = 1, ansR = 1, curL = 1;

    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;

        if (curSum + x < x) {
            curSum = x;
            curL = i;
        } else {
            curSum += x;
        }

        if (curSum > bestSum) {
            bestSum = curSum;
            ansL = curL;
            ansR = i;
        }
    }

    cout << ansL << ' ' << ansR << ' ' << bestSum << '\n';
    return 0;
}
