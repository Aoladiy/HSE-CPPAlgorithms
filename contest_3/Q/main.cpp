#include <iostream>
#include <string>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string s(n, '0');

    while (true) {
        std::cout << s << '\n';

        int i = n - 1;
        while (i >= 0 && s[i] - '0' == k - 1) {
            s[i] = '0';
            i--;
        }
        if (i < 0) break;
        s[i]++;
    }

    return 0;
}
