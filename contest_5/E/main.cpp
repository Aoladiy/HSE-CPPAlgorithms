#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    for (auto &[val, cnt]: freq) {
        if (cnt != 4) {
            cout << val << '\n';
            return 0;
        }
    }

    return 0;
}
