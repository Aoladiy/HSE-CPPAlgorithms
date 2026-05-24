#include <iostream>
#include <vector>

struct Node {
    int key;
    int left;
    int right;

    explicit Node(const int k) : key(k), left(-1), right(-1) {
    }
};

int main() {
    std::vector<Node> nodes;
    int root = -1;

    int value;
    while (std::cin >> value && value != 0) {
        const int new_idx = static_cast<int>(nodes.size());
        nodes.emplace_back(value);

        if (root == -1) {
            root = new_idx;
            continue;
        }

        int cur = root;
        while (true) {
            if (value == nodes[cur].key) {
                nodes.pop_back();
                break;
            }
            if (value < nodes[cur].key) {
                if (nodes[cur].left == -1) {
                    nodes[cur].left = new_idx;
                    break;
                }
                cur = nodes[cur].left;
            } else {
                if (nodes[cur].right == -1) {
                    nodes[cur].right = new_idx;
                    break;
                }
                cur = nodes[cur].right;
            }
        }
    }

    std::vector<int> stk;
    int cur = root;

    while (cur != -1 || !stk.empty()) {
        while (cur != -1) {
            stk.push_back(cur);
            cur = nodes[cur].left;
        }
        cur = stk.back();
        stk.pop_back();

        if (nodes[cur].left == -1 && nodes[cur].right == -1) {
            std::cout << nodes[cur].key << '\n';
        }

        cur = nodes[cur].right;
    }

    return 0;
}
