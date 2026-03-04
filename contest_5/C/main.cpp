#include <iostream>
#include <string>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    bool beautiful[26][26] = {};

    for (int i = 0; i < k; i++) {
        std::string pair;
        std::cin >> pair;
        const char a = pair[0];
        const char b = pair[1];
        beautiful[a - 'a'][b - 'a'] = true;
    }

    long long count[26] = {};
    long long ans = 0;

    for (int j = 0; j < n; j++) {
        const int bj = s[j] - 'a';
        for (int a = 0; a < 26; a++) {
            if (beautiful[a][bj]) {
                ans += count[a];
            }
        }
        count[bj]++;
    }

    std::cout << ans << std::endl;
    return 0;
}
