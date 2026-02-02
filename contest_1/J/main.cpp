#include <complex>
#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << std::fixed << std::sqrt(std::pow(a, 2) + std::pow(b, 2));
}
