#include <vector>
#include <algorithm>
#include <iostream>

struct BinaryTree {
    struct Node {
        int key;
        int left;
        int right;

        explicit Node(const int k) : key(k), left(-1), right(-1) {
        }
    };

    std::vector<Node> nodes_;
    int root_;

    BinaryTree() : root_(-1) {
    }

    void insert(const int value) {
        const int new_idx = static_cast<int>(nodes_.size());
        nodes_.emplace_back(value);

        if (root_ == -1) {
            root_ = new_idx;
            return;
        }

        int cur = root_;
        while (true) {
            if (value < nodes_[cur].key) {
                if (nodes_[cur].left == -1) {
                    nodes_[cur].left = new_idx;
                    return;
                }
                cur = nodes_[cur].left;
            } else {
                if (nodes_[cur].right == -1) {
                    nodes_[cur].right = new_idx;
                    return;
                }
                cur = nodes_[cur].right;
            }
        }
    }

    int checkAvl(const int v) {
        if (v == -1) {
            return 0;
        }
        const int lh = checkAvl(nodes_[v].left);
        if (lh == -1) {
            return -1;
        }
        const int rh = checkAvl(nodes_[v].right);
        if (rh == -1) {
            return -1;
        }
        if (std::abs(lh - rh) > 1) {
            return -1;
        }
        return 1 + std::max(lh, rh);
    }

    bool isAvl() {
        return checkAvl(root_) != -1;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    BinaryTree tree;
    int value;
    while (std::cin >> value && value != 0) {
        tree.insert(value);
    }

    std::cout << (tree.isAvl() ? "YES" : "NO") << '\n';
    return 0;
}
