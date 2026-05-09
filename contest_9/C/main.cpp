#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<char> st;
    st.reserve(s.size());

    for (char c: s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push_back(c);
        } else {
            if (st.empty()) {
                cout << "NO\n";
                return 0;
            }
            const char top = st.back();
            st.pop_back();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << (st.empty() ? "YES" : "NO") << "\n";
    return 0;
}
