#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Node {
    int value;
    int priority;
    int size;
    Node *left;
    Node *right;

    explicit Node(const int v) : value(v), priority(rand()), size(1), left(nullptr), right(nullptr) {
    }
};

int getSize(const Node *t) {
    return t ? t->size : 0;
}

void updateSize(Node *t) {
    if (t) t->size = 1 + getSize(t->left) + getSize(t->right);
}

void split(Node *t, const int k, Node *&left, Node *&right) {
    if (!t) {
        left = right = nullptr;
        return;
    }
    if (const int leftSize = getSize(t->left); leftSize < k) {
        split(t->right, k - leftSize - 1, t->right, right);
        left = t;
    } else {
        split(t->left, k, left, t->left);
        right = t;
    }
    updateSize(t);
}

Node *merge(Node *left, Node *right) {
    if (!left) return right;
    if (!right) return left;

    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        updateSize(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        updateSize(right);
        return right;
    }
}

Node *buildBalanced(const vector<int> &values, int l, int r) {
    if (l > r) return nullptr;
    const int mid = (l + r) / 2;
    const auto node = new Node(values[mid]);
    node->left = buildBalanced(values, l, mid - 1);
    node->right = buildBalanced(values, mid + 1, r);
    updateSize(node);
    return node;
}

void collect(Node *t, vector<int> &result) {
    if (!t) return;
    collect(t->left, result);
    result.push_back(t->value);
    collect(t->right, result);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> initial(n);
    for (int i = 0; i < n; ++i) initial[i] = i + 1;

    Node *root = buildBalanced(initial, 0, n - 1);

    for (int q = 0; q < m; ++q) {
        int l, r;
        cin >> l >> r;

        Node *left, *mid, *right;
        split(root, r, left, right);
        split(left, l - 1, left, mid);
        root = merge(mid, merge(left, right));
    }

    vector<int> result;
    result.reserve(n);
    collect(root, result);

    for (int i = 0; i < n; ++i) {
        cout << result[i];
        if (i + 1 < n) cout << ' ';
    }
    cout << '\n';

    return 0;
}
