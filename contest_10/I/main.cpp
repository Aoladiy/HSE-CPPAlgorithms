#include <algorithm>

struct Node {
    int height;
    Node *left;
    Node *right;
    int value;

    explicit Node(const int v) : height(1), left(nullptr), right(nullptr), value(v) {
    }

    ~Node() = default;
};

class AVLTree {
    Node *root_;
    int size_;

    static int h(const Node *v) {
        return v == nullptr ? 0 : v->height;
    }

    static void updateHeight(Node *v) {
        v->height = 1 + std::max(h(v->left), h(v->right));
    }

    static int balanceFactor(const Node *v) {
        return h(v->left) - h(v->right);
    }

    static Node *rotateRight(Node *y) {
        Node *x = y->left;
        Node *t = x->right;
        x->right = y;
        y->left = t;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    static Node *rotateLeft(Node *x) {
        Node *y = x->right;
        Node *t = y->left;
        y->left = x;
        x->right = t;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    static Node *balance(Node *v) {
        updateHeight(v);
        const int bf = balanceFactor(v);
        if (bf == 2) {
            if (balanceFactor(v->left) < 0) {
                v->left = rotateLeft(v->left);
            }
            return rotateRight(v);
        }
        if (bf == -2) {
            if (balanceFactor(v->right) > 0) {
                v->right = rotateRight(v->right);
            }
            return rotateLeft(v);
        }
        return v;
    }

    Node *insertRec(Node *v, const int value) {
        if (v == nullptr) {
            ++size_;
            return new Node(value);
        }
        if (value == v->value) {
            return v;
        }
        if (value < v->value) {
            v->left = insertRec(v->left, value);
        } else {
            v->right = insertRec(v->right, value);
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

    Node *eraseRec(Node *v, const int value) {
        if (v == nullptr) {
            return nullptr;
        }
        if (value < v->value) {
            v->left = eraseRec(v->left, value);
        } else if (value > v->value) {
            v->right = eraseRec(v->right, value);
        } else {
            Node *l = v->left;
            Node *r = v->right;
            delete v;
            --size_;
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

    static void destroyRec(const Node *v) {
        if (v == nullptr) {
            return;
        }
        destroyRec(v->left);
        destroyRec(v->right);
        delete v;
    }

    static int fillTraversal(const Node *v, int *arr, int idx) {
        if (v == nullptr) {
            return idx;
        }
        idx = fillTraversal(v->left, arr, idx);
        arr[idx++] = v->value;
        idx = fillTraversal(v->right, arr, idx);
        return idx;
    }

public:
    AVLTree() : root_(nullptr), size_(0) {
    }

    explicit AVLTree(const int value) : root_(new Node(value)), size_(1) {
    }

    ~AVLTree() {
        destroyRec(root_);
    }

    [[nodiscard]] int getHeight() const {
        return h(root_);
    }

    void insert(const int value) {
        root_ = insertRec(root_, value);
    }

    void erase(const int value) {
        root_ = eraseRec(root_, value);
    }

    [[nodiscard]] int *find(const int value) const {
        Node *cur = root_;
        while (cur != nullptr) {
            if (value == cur->value) {
                return &cur->value;
            }
            cur = value < cur->value ? cur->left : cur->right;
        }
        return nullptr;
    }

    [[nodiscard]] int *traversal() const {
        if (size_ == 0) {
            return nullptr;
        }
        const auto arr = new int[size_];
        fillTraversal(root_, arr, 0);
        return arr;
    }

    [[nodiscard]] int *lowerBound(const int value) const {
        Node *cur = root_;
        Node *result = nullptr;
        while (cur != nullptr) {
            if (cur->value >= value) {
                result = cur;
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return result == nullptr ? nullptr : &result->value;
    }

    [[nodiscard]] bool empty() const {
        return root_ == nullptr;
    }

    [[nodiscard]] Node *getRoot() const {
        return root_;
    }

    [[nodiscard]] int getSize() const {
        return size_;
    }
};
