#include <iostream>
#include <string>

int main() {
    int num;
    std::cin >> num;
    std::cout << "The next number for the number " << num << " is " << num + 1 << ".\n";
    std::cout << "The previous number for the number " << num << " is " << num - 1 << ".";
}
