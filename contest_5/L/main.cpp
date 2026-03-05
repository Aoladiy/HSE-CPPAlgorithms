#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector cnt(k, 0);
    int have = 0;
    int left = 0;
    int bestLen = INT_MAX, ansL = 0, ansR = 0;

    for (int right = 0; right < n; right++) {
        if (cnt[a[right]] == 0) have++;
        cnt[a[right]]++;

        while (have == k) {
            if (right - left + 1 < bestLen) {
                bestLen = right - left + 1;
                ansL = left;
                ansR = right;
            }
            cnt[a[left]]--;
            if (cnt[a[left]] == 0) have--;
            left++;
        }
    }

    cout << ansL + 1 << ' ' << ansR + 1 << '\n';
    return 0;
}
