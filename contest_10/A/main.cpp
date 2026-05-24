#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key, left, right;
};

vector<Node> tree;
vector<int> inorder_result, preorder_result, postorder_result;

void inorder(const int v) {
    if (v == -1) return;
    inorder(tree[v].left);
    inorder_result.push_back(tree[v].key);
    inorder(tree[v].right);
}

void preorder(const int v) {
    if (v == -1) return;
    preorder_result.push_back(tree[v].key);
    preorder(tree[v].left);
    preorder(tree[v].right);
}

void postorder(const int v) {
    if (v == -1) return;
    postorder(tree[v].left);
    postorder(tree[v].right);
    postorder_result.push_back(tree[v].key);
}

void printResult(const vector<int> &res) {
    for (int i = 0; i < static_cast<int>(res.size()); i++) {
        if (i > 0) cout << ' ';
        cout << res[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    tree.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i].key >> tree[i].left >> tree[i].right;
    }

    inorder(0);
    preorder(0);
    postorder(0);

    printResult(inorder_result);
    printResult(preorder_result);
    printResult(postorder_result);

    return 0;
}
