#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    vector<int> st;
    vector<int> mx;

    while (q--) {
        string op;
        cin >> op;

        if (op == "push") {
            int v;
            cin >> v;
            st.push_back(v);
            mx.push_back(mx.empty() ? v : max(v, mx.back()));
        } else if (op == "pop") {
            st.pop_back();
            mx.pop_back();
        } else {
            cout << mx.back() << "\n";
        }
    }

    return 0;
}
