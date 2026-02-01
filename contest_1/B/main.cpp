#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    const bool result = a < b && b < c;
    std::cout << result;
    return 0;
}
