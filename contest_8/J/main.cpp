#include <iostream>
#include <string>

struct Node {
    int value;
    Node *next;

    explicit Node(const int v) : value(v), next(nullptr) {
    }
};

void clearList(const Node *head) {
    while (head) {
        const Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    const Node *head = nullptr;
    Node *tail = nullptr;
    const Node *counter = nullptr;

    std::string cmd;
    int n;

    while (std::cin >> cmd >> n) {
        if (cmd == "exit") break;

        if (cmd == "push") {
            const auto node = new Node(n);
            if (!head) {
                head = tail = node;
                counter = head;
            } else {
                tail->next = node;
                tail = node;
            }
            std::cout << "added\n";
        } else {
            for (int j = 0; j < n; j++) counter = counter->next;
            std::cout << counter->value << "\n";
        }
    }

    clearList(head);
    return 0;
}
