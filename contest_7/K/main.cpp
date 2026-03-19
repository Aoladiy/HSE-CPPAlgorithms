#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, a, k, b, m;
    cin >> n >> a >> k >> b >> m;

    vector<long long> tails;

    for (long long i = 0; i < n; i++) {
        if (auto it = ranges::lower_bound(tails, a); it == tails.end())
            tails.push_back(a);
        else
            *it = a;
        a = (k * a + b) % m;
    }

    cout << tails.size() << "\n";
    return 0;
}
