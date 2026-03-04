#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    constexpr int OFFSET = 10000;
    int freq[20001] = {};

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x + OFFSET]++;
    }

    bool first = true;
    for (int i = 0; i <= 20000; i++) {
        for (int j = 0; j < freq[i]; j++) {
            if (!first) cout << ' ';
            cout << (i - OFFSET);
            first = false;
        }
    }
    cout << '\n';

    return 0;
}
