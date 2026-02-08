#include <algorithm>
#include <iostream>

int main() {
    std::string word_to_reverse;
    std::cin >> word_to_reverse;
    const std::string word = word_to_reverse;
    std::ranges::reverse(word_to_reverse);
    if (word == word_to_reverse) {
        std::cout << "yes";
        return 0;
    }
    std::cout << "no";
    return 0;
}
