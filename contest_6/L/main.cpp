#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector t(n, vector<long long>());

    for (int i = 0; i < n; i++) {
        t[i].resize(i + 1);
        t[i][0] = t[i][i] = 1;
        for (int j = 1; j < i; j++)
            t[i][j] = t[i - 1][j - 1] + t[i - 1][j];

        for (int j = 0; j <= i; j++) {
            if (j > 0) cout << " ";
            cout << t[i][j];
        }
        cout << "\n";
    }

    return 0;
}
