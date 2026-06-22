#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<int> order(n);
    for (int i = 0; i < n; ++i) order[i] = i;
    ranges::sort(order, [&](const int x, const int y) {
        return a[x] < a[y];
    });

    vector<int> parent(n, -1), left(n, -1), right(n, -1);
    vector<int> stack_idx;
    stack_idx.reserve(n);

    for (int idx: order) {
        int lastPopped = -1;

        while (!stack_idx.empty() && b[stack_idx.back()] > b[idx]) {
            lastPopped = stack_idx.back();
            stack_idx.pop_back();
        }

        if (!stack_idx.empty()) {
            right[stack_idx.back()] = idx;
            parent[idx] = stack_idx.back();
        }

        if (lastPopped != -1) {
            left[idx] = lastPopped;
            parent[lastPopped] = idx;
        }

        stack_idx.push_back(idx);
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        const int p = (parent[i] == -1) ? 0 : parent[i] + 1;
        const int l = (left[i] == -1) ? 0 : left[i] + 1;
        const int r = (right[i] == -1) ? 0 : right[i] + 1;
        cout << p << ' ' << l << ' ' << r << '\n';
    }

    return 0;
}
