#include <iostream>
#include <string>
#include <vector>

class Queue {
    std::vector<long long> data;
    size_t head = 0;

public:
    void push(const long long val) { data.push_back(val); }

    long long pop() {
        const long long val = data[head];
        head++;
        return val;
    }

    [[nodiscard]] long long front() const { return data[head]; }
    [[nodiscard]] size_t size() const { return data.size() - head; }
    [[nodiscard]] bool empty() const { return head >= data.size(); }

    void clear() {
        data.clear();
        head = 0;
    }
};

int main() {
    Queue q;
    std::string cmd;

    while (std::cin >> cmd) {
        if (cmd == "push") {
            long long val;
            std::cin >> val;
            q.push(val);
            std::cout << "ok\n";
        } else if (cmd == "pop") {
            if (q.empty()) { std::cout << "error\n"; } else { std::cout << q.pop() << "\n"; }
        } else if (cmd == "front") {
            if (q.empty()) { std::cout << "error\n"; } else { std::cout << q.front() << "\n"; }
        } else if (cmd == "size") {
            std::cout << q.size() << "\n";
        } else if (cmd == "clear") {
            q.clear();
            std::cout << "ok\n";
        } else if (cmd == "exit") {
            std::cout << "bye\n";
            return 0;
        }
    }
    return 0;
}
