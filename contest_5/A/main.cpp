#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int count = 0;
    for (const char c: s) {
        if (c == '(') count++;
        else if (c == ')') count--;
        if (count < 0) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << (count == 0 ? "YES" : "NO") << std::endl;
    return 0;
}
