#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> have;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        have.insert(x);
    }

    cout << 15000 - static_cast<int>(have.size()) << '\n';
    return 0;
}
