#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Node {
    long long value;
    int priority;
    int size;
    long long sum;
    Node *left;
    Node *right;

    explicit Node(const long long v) : value(v), priority(rand()), size(1), sum(v), left(nullptr), right(nullptr) {
    }
};

int getSize(const Node *t) { return t ? t->size : 0; }
long long getSum(const Node *t) { return t ? t->sum : 0; }

void update(Node *t) {
    if (t) {
        t->size = 1 + getSize(t->left) + getSize(t->right);
        t->sum = t->value + getSum(t->left) + getSum(t->right);
    }
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
    update(t);
}

Node *merge(Node *left, Node *right) {
    if (!left) return right;
    if (!right) return left;
    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        update(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        update(right);
        return right;
    }
}

void collectInOrder(const Node *t, vector<long long> &values) {
    if (!t) return;
    collectInOrder(t->left, values);
    values.push_back(t->value);
    collectInOrder(t->right, values);
}

void assignInOrder(Node *t, const vector<long long> &values, int &idx) {
    if (!t) return;
    assignInOrder(t->left, values, idx);
    t->value = values[idx++];
    assignInOrder(t->right, values, idx);
    update(t);
}

Node *swapPairsInSubtree(Node *t) {
    vector<long long> values;
    collectInOrder(t, values);
    for (size_t i = 0; i + 1 < values.size(); i += 2) {
        swap(values[i], values[i + 1]);
    }
    int idx = 0;
    assignInOrder(t, values, idx);
    return t;
}

Node *buildBalanced(const vector<long long> &values, const int l, const int r) {
    if (l > r) return nullptr;
    const int mid = (l + r) / 2;
    const auto node = new Node(values[mid]);
    node->left = buildBalanced(values, l, mid - 1);
    node->right = buildBalanced(values, mid + 1, r);
    update(node);
    return node;
}

int main() {
    int n, m;
    int testNum = 0;
    bool firstTest = true;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        ++testNum;

        vector<long long> values(n);
        for (int i = 0; i < n; ++i) cin >> values[i];

        Node *root = buildBalanced(values, 0, n - 1);

        vector<long long> answers;
        for (int q = 0; q < m; ++q) {
            int type;
            long long a, b;
            cin >> type >> a >> b;

            Node *left, *mid, *right;
            split(root, static_cast<int>(b), left, right);
            split(left, static_cast<int>(a) - 1, left, mid);

            if (type == 1) {
                mid = swapPairsInSubtree(mid);
            } else {
                answers.push_back(getSum(mid));
            }

            root = merge(merge(left, mid), right);
        }

        if (!firstTest) cout << '\n';
        firstTest = false;

        cout << "Swapper " << testNum << ":\n";
        for (const long long ans: answers) {
            cout << ans << '\n';
        }
    }

    return 0;
}
