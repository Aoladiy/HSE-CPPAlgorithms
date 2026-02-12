#include <iostream>
#include <string>


std::string CommonSuffix(const std::string &a, const std::string &b) {
    int i = static_cast<int>(a.length()) - 1;
    int j = static_cast<int>(b.length()) - 1;

    while (i >= 0 && j >= 0 && a[i] == b[j]) {
        i--;
        j--;
    }

    return a.substr(i + 1);
}

int main() {
    std::string a, b;
    std::cin >> a >> b;

    std::cout << CommonSuffix(a, b);

    return 0;
}
