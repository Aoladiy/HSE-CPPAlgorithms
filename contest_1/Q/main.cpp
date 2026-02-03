#include <cstring>
#include <iostream>
#include <string>

int main() {
    std::string words;
    std::getline(std::cin, words);
    int spacesCount = 0;
    int counter = 0;
    for (char ch: words) {
        counter++;
        if (ch == ' ') {
            spacesCount++;
        }
    }
    if (counter == 0) {
        std::cout << 0;
    } else {
        std::cout << spacesCount + 1;
    }
}
