#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    long long key;
    int priority;
    Node *left;
    Node *right;

    explicit Node(const long long k) : key(k), priority(rand()), left(nullptr), right(nullptr) {
    }
};

void split(Node *t, const long long key, Node *&left, Node *&right) {
    if (!t) {
        left = right = nullptr;
        return;
    }
    if (t->key < key) {
        split(t->right, key, t->right, right);
        left = t;
    } else {
        split(t->left, key, left, t->left);
        right = t;
    }
}

Node *merge(Node *left, Node *right) {
    if (!left) return right;
    if (!right) return left;

    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        return left;
    } else {
        right->left = merge(left, right->left);
        return right;
    }
}

Node *insert(Node *t, const long long key) {
    Node *left;
    Node *right;
    split(t, key, left, right);

    Node *leftLeft;
    Node *leftRight;
    split(left, key, leftLeft, leftRight);
    if (leftRight && leftRight->key == key) {
        return merge(merge(leftLeft, leftRight), right);
    }

    const auto newNode = new Node(key);
    return merge(merge(leftLeft, leftRight), merge(newNode, right));
}

Node *erase(Node *t, const long long key) {
    if (!t) return nullptr;
    if (t->key == key) {
        Node *result = merge(t->left, t->right);
        delete t;
        return result;
    }
    if (key < t->key) {
        t->left = erase(t->left, key);
    } else {
        t->right = erase(t->right, key);
    }
    return t;
}

bool exists(const Node *t, const long long key) {
    while (t) {
        if (t->key == key) return true;
        t = (key < t->key) ? t->left : t->right;
    }
    return false;
}

int main() {
    srand(12345);

    Node *root = nullptr;
    string op;

    while (cin >> op) {
        long long x;
        cin >> x;

        if (op == "insert") {
            if (!exists(root, x)) {
                root = insert(root, x);
            }
        } else if (op == "delete") {
            root = erase(root, x);
        } else if (op == "exists") {
            cout << (exists(root, x) ? "true" : "false") << '\n';
        }
    }

    return 0;
}
