#include <iostream>

int main() {
    long long next;
    while (true) {
        std::cin >> next;
        if (next == 0) {
            return 0;
        }
        std::cout << static_cast<char>(next);
    }
}
