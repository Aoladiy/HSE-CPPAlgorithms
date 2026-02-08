#include <iostream>

int main() {
    std::string first_str;
    std::string second_str;
    std::cin >> first_str >> second_str;
    if (const auto substring_idx = static_cast<long long>(second_str.find(first_str)); substring_idx == -1) {
        std::cout << "no";
        return 0;
    }
    std::cout << "yes";
    return 0;
}
