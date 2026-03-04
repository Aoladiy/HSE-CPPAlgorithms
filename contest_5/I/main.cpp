#include <iostream>
#include <vector>
using namespace std;

int main() {

    long long n, r;
    cin >> n >> r;

    vector<long long> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    const long long total = n * (n - 1) / 2;
    long long close = 0;
    int left = 0;
    for (int right = 1; right < n; right++) {
        while (d[right] - d[left] > r) left++;
        close += right - left;
    }

    cout << total - close << '\n';
    return 0;
}
