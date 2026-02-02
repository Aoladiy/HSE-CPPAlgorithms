#include <complex>
#include <iostream>

int main() {
    int operationCode;
    double a, b;
    std::cin >> operationCode >> a >> b;
    switch (operationCode) {
        case 0:
            std::cout << a + b;
            break;
        case 1:
            std::cout << a - b;
            break;
        case 2:
            std::cout << a * b;
            break;
        case 3:
            std::cout << a / b;
            break;
        case 4:
            std::cout << std::pow(a, b);
            break;
        case 5:
            std::cout << std::pow(b, 1.0 / a);
            break;
        default:
            std::cout << -1;
    }
}
