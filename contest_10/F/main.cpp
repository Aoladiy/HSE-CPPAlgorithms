#include <vector>
#include <algorithm>

class Tree {
    struct Node {
        int key;
        int left;
        int right;
        int height;

        explicit Node(const int k) : key(k), left(-1), right(-1), height(1) {
        }
    };

    std::vector<Node> nodes_;
    int root_;

    [[nodiscard]] int h(const int v) const {
        return v == -1 ? 0 : nodes_[v].height;
    }

    void updateHeight(const int v) {
        nodes_[v].height = 1 + std::max(h(nodes_[v].left), h(nodes_[v].right));
    }

    [[nodiscard]] int balanceFactor(const int v) const {
        return h(nodes_[v].left) - h(nodes_[v].right);
    }

    int rotateRight(const int y) {
        const int x = nodes_[y].left;
        const int t = nodes_[x].right;
        nodes_[x].right = y;
        nodes_[y].left = t;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    int rotateLeft(const int x) {
        const int y = nodes_[x].right;
        const int t = nodes_[y].left;
        nodes_[y].left = x;
        nodes_[x].right = t;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    int balance(const int v) {
        updateHeight(v);
        const int bf = balanceFactor(v);
        if (bf == 2) {
            if (balanceFactor(nodes_[v].left) < 0) {
                nodes_[v].left = rotateLeft(nodes_[v].left);
            }
            return rotateRight(v);
        }
        if (bf == -2) {
            if (balanceFactor(nodes_[v].right) > 0) {
                nodes_[v].right = rotateRight(nodes_[v].right);
            }
            return rotateLeft(v);
        }
        return v;
    }

    int insertRec(const int v, const int key) {
        if (v == -1) {
            nodes_.emplace_back(key);
            return static_cast<int>(nodes_.size()) - 1;
        }
        if (key == nodes_[v].key) {
            return v;
        }
        if (key < nodes_[v].key) {
            nodes_[v].left = insertRec(nodes_[v].left, key);
        } else {
            nodes_[v].right = insertRec(nodes_[v].right, key);
        }
        return balance(v);
    }

    void inorderIter(std::vector<int> &stk, int &last, int &second) {
        int cur = root_;
        while (cur != -1 || !stk.empty()) {
            while (cur != -1) {
                stk.push_back(cur);
                cur = nodes_[cur].left;
            }
            cur = stk.back();
            stk.pop_back();
            second = last;
            last = nodes_[cur].key;
            cur = nodes_[cur].right;
        }
    }

public:
    Tree() : root_(-1) {
    }

    ~Tree() = default;

    void insert(const int value) {
        root_ = insertRec(root_, value);
    }

    int max2() {
        std::vector<int> stk;
        stk.reserve(nodes_.size());
        int last = -1;
        int second = -1;
        inorderIter(stk, last, second);
        return second;
    }
};
