#include <iostream>
#include <string>

void generateBinaryStrings(const std::string& current, const int n, const int length) {
    if (static_cast<int>(current.length()) == length) {
        std::cout << current << std::endl;
        return;
    }

    generateBinaryStrings(current + "0", n, length);

    generateBinaryStrings(current + "1", n, length);
}

int main() {
    int n;
    std::cin >> n;

    generateBinaryStrings("", n, n);

    return 0;
}