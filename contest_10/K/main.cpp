#include <iostream>
#include <cstdint>
#include <algorithm>

static constexpr int kMaxn = 300005;
static constexpr int64_t kMod = 1000000000LL;

struct Node {
    int64_t value;
    int height;
    Node *left;
    Node *right;
};

static Node pool[kMaxn];
static int pool_idx = 0;

static Node *newNode(const int64_t v) {
    Node *nd = &pool[pool_idx++];
    nd->value = v;
    nd->height = 1;
    nd->left = nullptr;
    nd->right = nullptr;
    return nd;
}

static int h(const Node *v) {
    return v == nullptr ? 0 : v->height;
}

static void update(Node *v) {
    v->height = 1 + std::max(h(v->left), h(v->right));
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

static int64_t lowerBound(const Node *v, const int64_t value) {
    int64_t result = -1;
    while (v != nullptr) {
        if (v->value >= value) {
            result = v->value;
            v = v->left;
        } else {
            v = v->right;
        }
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    Node *root = nullptr;
    int64_t last = 0;
    bool last_was_query = false;

    while (n--) {
        char op;
        int64_t x;
        std::cin >> op >> x;

        if (op == '+') {
            int64_t val = x;
            if (last_was_query) {
                val = (x + last) % kMod;
            }
            root = insert(root, val);
            last_was_query = false;
        } else {
            last = lowerBound(root, x);
            std::cout << last << '\n';
            last_was_query = true;
        }
    }

    return 0;
}
