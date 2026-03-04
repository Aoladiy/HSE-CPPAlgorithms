#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    static long long pre[100001];
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        if (i > 0) cout << ' ';
        cout << pre[r] - pre[l - 1];
    }
    cout << '\n';
    return 0;
}
