#include <iostream>

int main() {
    std::string num;
    std::cin >> num;
    int digitsSum = 0;
    for (const char digit: num) {
        digitsSum += static_cast<int>(digit) - '0';
    }
    std::cout << digitsSum;
    return 0;
}
