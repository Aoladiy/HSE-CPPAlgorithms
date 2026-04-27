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
    int n, m;
    std::cin >> n >> m;

    Node *head = nullptr;
    Node *tail = nullptr;

    for (int i = 0; i < n; i++) {
        int v;
        std::cin >> v;
        const auto node = new Node(v);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    for (int i = 0; i < m; i++) {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "insert") {
            int value, pos;
            std::cin >> value >> pos;
            const auto newNode = new Node(value);
            if (pos == 0) {
                newNode->next = head;
                head = newNode;
            } else {
                Node *cur = head;
                for (int j = 0; j < pos; j++) cur = cur->next;
                newNode->next = cur->next;
                cur->next = newNode;
                if (!newNode->next) tail = newNode;
            }
        } else {
            int pos;
            std::cin >> pos;
            Node *cur = head;
            for (int j = 0; j < pos; j++) cur = cur->next;
            const Node *tmp = cur->next;
            cur->next = tmp->next;
            if (!cur->next) tail = cur;
            delete tmp;
        }
    }

    for (const Node *cur = head; cur; cur = cur->next) {
        std::cout << cur->value;
        if (cur->next) std::cout << " ";
    }
    std::cout << "\n";

    clearList(head);
    return 0;
}
