#include <iostream>
#include <string>

std::pair<size_t, size_t> FindVowels(const std::string &str, size_t pos) {
    while (pos < str.length()) {
        if (const char c = str[pos];
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y'
        ) {
            size_t start = pos;
            size_t length = 0;

            while (pos < str.length()) {
                if (const char crnt = str[pos];
                    crnt == 'a' || crnt == 'e' || crnt == 'i' || crnt == 'o' || crnt == 'u' || crnt == 'y' ||
                    crnt == 'A' || crnt == 'E' || crnt == 'I' || crnt == 'O' || crnt == 'U' || crnt == 'Y'
                ) {
                    length++;
                    pos++;
                } else {
                    break;
                }
            }

            return {start, length};
        }
        pos++;
    }

    return {std::string::npos, 0};
}

using namespace std;

int main() {
    string text;
    getline(cin, text);
    size_t pos = 0;
    while (true) {
        auto [start, length] = FindVowels(text, pos);
        if (start == string::npos)
            break;
        cout << start << " " << length << " " << text.substr(start, length) << "\n";
        pos = start + length;
    }
}
