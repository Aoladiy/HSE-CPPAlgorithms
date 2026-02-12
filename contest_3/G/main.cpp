#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> Split(const std::string &str, const char delimiter) {
    std::vector<std::string> result;
    std::string current;

    for (int i = 0; i < static_cast<int>(str.length()); ++i) {
        if (str[i] == delimiter) {
            result.push_back(current);
            current = "";
        } else {
            current += str[i];
        }
    }

    result.push_back(current);

    return result;
}

int main() {
    std::string str;
    char delimiter;

    std::getline(std::cin, str);
    std::cin >> delimiter;

    for (const std::vector<std::string> parts = Split(str, delimiter); const std::string &part: parts) {
        std::cout << part << '\n';
    }

    return 0;
}
