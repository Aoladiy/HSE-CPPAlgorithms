#include <iostream>

int main() {
    std::string word;
    std::cin >> word;
    const auto first_idx = static_cast<long long>(word.find('f'));
    const auto last_idx = static_cast<long long>(word.rfind('f'));
    if (first_idx == -1) {
        return 0;
    }
    if (first_idx == last_idx) {
        std::cout << first_idx;
        return 0;
    }
    std::cout << first_idx << " " << last_idx;
    return 0;
}
