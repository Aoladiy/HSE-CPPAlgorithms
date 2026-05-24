#include <vector>
#include <algorithm>

class Tree {
    struct Node {
        int key, left, right;

        explicit Node(const int k) : key(k), left(-1), right(-1) {
        }
    };

    std::vector<Node> nodes_;
    int root_;

public:
    Tree() : root_(-1) {
    }

    ~Tree() = default;

    void insert(const int value) {
        const int new_idx = static_cast<int>(nodes_.size());
        nodes_.emplace_back(value);

        if (root_ == -1) {
            root_ = new_idx;
            return;
        }

        int cur = root_;
        while (true) {
            if (value == nodes_[cur].key) {
                nodes_.pop_back();
                return;
            }
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

    size_t getHeight() {
        if (root_ == -1) {
            return 0;
        }

        std::vector<std::pair<int, int> > queue(nodes_.size() * 2);
        int head = 0, tail = 0;
        queue[tail++] = {root_, 1};
        size_t max_h = 0;

        while (head < tail) {
            auto [v, h] = queue[head++];
            max_h = std::max(max_h, static_cast<size_t>(h));
            if (nodes_[v].left != -1) {
                queue[tail++] = {nodes_[v].left, h + 1};
            }
            if (nodes_[v].right != -1) {
                queue[tail++] = {nodes_[v].right, h + 1};
            }
        }
        return max_h;
    }
};
