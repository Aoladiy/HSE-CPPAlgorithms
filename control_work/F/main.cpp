#include <iostream>
#include <string>

bool CheckPalindrome(const std::string &s) {
    int l = 0;
    int r = static_cast<int>(s.size()) - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        ++l;
        --r;
    }
    return true;
}

bool CheckPalindrome(const std::string &s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        ++l;
        --r;
    }
    return true;
}

int CountPalindromes(const std::string &s) {
    int count = 0;
    const int n = static_cast<int>(s.size());
    int i = 0;

    while (i < n) {
        while (i < n && s[i] == ' ') ++i;
        if (i >= n) break;

        const int start = i;
        while (i < n && s[i] != ' ') ++i;

        if (const int end = i - 1; CheckPalindrome(s, start, end)) {
            ++count;
        }
    }
    return count;
}

int main() {
    std::string s;
    std::getline(std::cin, s);

    std::cout << "CountPalindromes = " << CountPalindromes(s) << '\n';

    return 0;
}
