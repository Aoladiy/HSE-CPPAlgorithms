#include <iostream>
#include <string>

int main() {
    std::string s;
    std::string s_without_spaces;
    std::string s_without_spaces_reversed;
    std::getline(std::cin, s);

    for (const char c: s) {
        if (c != ' ') {
            s_without_spaces.push_back(c);
        }
    }
    std::reverse_copy(s_without_spaces.begin(), s_without_spaces.end(), std::back_inserter(s_without_spaces_reversed));

    if (s_without_spaces == s_without_spaces_reversed) {
        std::cout << "yes";
        return 0;
    }

    std::cout << "no";
    return 0;
}
