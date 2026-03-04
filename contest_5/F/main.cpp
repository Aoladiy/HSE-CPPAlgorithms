#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ranges::sort(a);

    int best = 1, left = 0;
    for (int right = 1; right < n; right++) {
        if (a[right] >= 2 * a[right - 1]) {
            left = right;
        }
        best = max(best, right - left + 1);
    }

    cout << best << '\n';
    return 0;
}
