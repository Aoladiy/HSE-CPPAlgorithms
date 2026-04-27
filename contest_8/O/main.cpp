#include <iostream>
#include <deque>
#include <string>

int main() {
    std::deque<int> dek;
    std::string cmd;

    while (std::cin >> cmd) {
        if (cmd == "push_front") {
            int val;
            std::cin >> val;
            dek.push_front(val);
            std::cout << "ok\n";
        } else if (cmd == "push_back") {
            int val;
            std::cin >> val;
            dek.push_back(val);
            std::cout << "ok\n";
        } else if (cmd == "pop_front") {
            if (dek.empty()) { std::cout << "error\n"; } else {
                std::cout << dek.front() << "\n";
                dek.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (dek.empty()) { std::cout << "error\n"; } else {
                std::cout << dek.back() << "\n";
                dek.pop_back();
            }
        } else if (cmd == "front") {
            if (dek.empty()) { std::cout << "error\n"; } else { std::cout << dek.front() << "\n"; }
        } else if (cmd == "back") {
            if (dek.empty()) { std::cout << "error\n"; } else { std::cout << dek.back() << "\n"; }
        } else if (cmd == "size") {
            std::cout << dek.size() << "\n";
        } else if (cmd == "clear") {
            dek.clear();
            std::cout << "ok\n";
        } else if (cmd == "exit") {
            std::cout << "bye\n";
            return 0;
        }
    }
    return 0;
}
