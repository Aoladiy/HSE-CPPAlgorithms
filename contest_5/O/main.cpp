#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<int, long long> freq;
    freq[0] = 1;
    int psum = 0;
    long long ans = 0;

    for (const char c: s) {
        psum += (c == 'a') ? 1 : -1;
        ans += freq[psum];
        freq[psum]++;
    }

    cout << ans << '\n';
    return 0;
}
