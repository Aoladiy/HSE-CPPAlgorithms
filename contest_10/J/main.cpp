#include <iostream>
#include <algorithm>
#include <cstdint>

static constexpr int kMaxn = 2000005;

struct Node {
    int64_t value;
    int height;
    int size;
    Node *left;
    Node *right;
};

static Node pool[kMaxn];
static int pool_idx = 0;

static Node *newNode(const int64_t v) {
    Node *nd = &pool[pool_idx++];
    nd->value = v;
    nd->height = 1;
    nd->size = 1;
    nd->left = nullptr;
    nd->right = nullptr;
    return nd;
}

static int h(const Node *v) {
    return v == nullptr ? 0 : v->height;
}

static int sz(const Node *v) {
    return v == nullptr ? 0 : v->size;
}

static void update(Node *v) {
    if (v == nullptr) {
        return;
    }
    v->height = 1 + std::max(h(v->left), h(v->right));
    v->size = 1 + sz(v->left) + sz(v->right);
}

static int bf(const Node *v) {
    return h(v->left) - h(v->right);
}

static Node *rotateRight(Node *y) {
    Node *x = y->left;
    Node *t = x->right;
    x->right = y;
    y->left = t;
    update(y);
    update(x);
    return x;
}

static Node *rotateLeft(Node *x) {
    Node *y = x->right;
    Node *t = y->left;
    y->left = x;
    x->right = t;
    update(x);
    update(y);
    return y;
}

static Node *balance(Node *v) {
    update(v);
    const int b = bf(v);
    if (b == 2) {
        if (bf(v->left) < 0) {
            v->left = rotateLeft(v->left);
        }
        return rotateRight(v);
    }
    if (b == -2) {
        if (bf(v->right) > 0) {
            v->right = rotateRight(v->right);
        }
        return rotateLeft(v);
    }
    return v;
}

static Node *insert(Node *v, const int64_t value) {
    if (v == nullptr) {
        return newNode(value);
    }
    if (value < v->value) {
        v->left = insert(v->left, value);
    } else if (value > v->value) {
        v->right = insert(v->right, value);
    }
    return balance(v);
}

static Node *findMin(Node *v) {
    return v->left == nullptr ? v : findMin(v->left);
}

static Node *removeMin(Node *v) {
    if (v->left == nullptr) {
        return v->right;
    }
    v->left = removeMin(v->left);
    return balance(v);
}

static Node *erase(Node *v, const int64_t value) {
    if (v == nullptr) {
        return nullptr;
    }
    if (value < v->value) {
        v->left = erase(v->left, value);
    } else if (value > v->value) {
        v->right = erase(v->right, value);
    } else {
        Node *l = v->left;
        Node *r = v->right;
        if (r == nullptr) {
            return l;
        }
        Node *mn = findMin(r);
        mn->right = removeMin(r);
        mn->left = l;
        return balance(mn);
    }
    return balance(v);
}

static int64_t kth(const Node *v, const int k) {
    const int left_size = sz(v->left);
    if (k == left_size + 1) {
        return v->value;
    }
    if (k <= left_size) {
        return kth(v->left, k);
    }
    return kth(v->right, k - left_size - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    Node *root = nullptr;

    while (n--) {
        char op;
        std::cin >> op;
        if (op == '+') {
            int64_t x;
            std::cin >> x;
            root = insert(root, x);
        } else if (op == '-') {
            int64_t x;
            std::cin >> x;
            root = erase(root, x);
        } else {
            int e;
            std::cin >> e;
            std::cout << kth(root, e) << '\n';
        }
    }

    return 0;
}
