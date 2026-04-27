#include <iostream>
#include <stdexcept>

constexpr int kMaxVal = 2e9;

class Node {
public:
    int data{};
    Node *next;
    Node *previous;

    Node() : next(nullptr), previous(nullptr) {
    }

    explicit Node(const int val) : data(val), next(nullptr), previous(nullptr) {
    }
};

class List {
public:
    Node *head{};
    Node *tail{};
    size_t size{};

    List() : head(nullptr), tail(nullptr), size(0) {
    }

    List(const int *values, const size_t n) : head(nullptr), tail(nullptr), size(0) {
        for (size_t i = 0; i < n; i++) {
            pushBack(values[i]);
        }
    }

    ~List() {
        Node *cur = head;
        while (cur) {
            Node *tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }

    void pushBack(const int value) {
        if (std::abs(value) > kMaxVal) {
            throw std::runtime_error("Wrong Value!");
        }
        const auto node = new Node(value);
        if (!head) {
            head = tail = node;
        } else {
            node->previous = tail;
            tail->next = node;
            tail = node;
        }
        size++;
    }

    void pushFront(const int value) {
        if (std::abs(value) > kMaxVal) {
            throw std::runtime_error("Wrong Value!");
        }
        const auto node = new Node(value);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->previous = node;
            head = node;
        }
        size++;
    }

    int pop() {
        if (!head) {
            throw std::runtime_error("Can not pop such element!");
        }
        const int val = head->data;
        Node *tmp = head;
        head = head->next;
        if (head) {
            head->previous = nullptr;
        } else {
            tail = nullptr;
        }
        delete tmp;
        size--;
        return val;
    }

    int pop(const size_t position) {
        if (position >= size) {
            throw std::runtime_error("Wrong Position!");
        }
        Node *cur = head;
        for (size_t i = 0; i < position; i++) {
            cur = cur->next;
        }
        const int val = cur->data;
        if (cur->previous) {
            cur->previous->next = cur->next;
        } else {
            head = cur->next;
        }
        if (cur->next) {
            cur->next->previous = cur->previous;
        } else {
            tail = cur->previous;
        }
        delete cur;
        size--;
        return val;
    }

    void push(const int value, const size_t position) {
        if (std::abs(value) > kMaxVal) {
            throw std::runtime_error("Wrong Value!");
        }
        if (position > size) {
            throw std::runtime_error("Wrong Position!");
        }
        if (position == size) {
            pushBack(value);
            return;
        }
        if (position == 0) {
            pushFront(value);
            return;
        }
        Node *cur = head;
        for (size_t i = 0; i < position; i++) {
            cur = cur->next;
        }
        const auto node = new Node(value);
        node->next = cur;
        node->previous = cur->previous;
        cur->previous->next = node;
        cur->previous = node;
        size++;
    }
};
