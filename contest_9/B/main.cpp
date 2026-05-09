#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int k;
    cin >> k;

    int zeros = 0;
    for (int i = 0; i < k; i++)
        if (a[i] == 0) zeros++;

    cout << zeros;

    for (int i = k; i < n; i++) {
        if (a[i] == 0) zeros++;
        if (a[i - k] == 0) zeros--;
        cout << " " << zeros;
    }

    cout << "\n";

    return 0;
}
