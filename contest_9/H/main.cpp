#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> st;
    long long ans = 0;

    for (int i = 0; i <= n; i++) {
        const long long cur = (i == n) ? 0 : h[i];

        while (!st.empty() && h[st.back()] > cur) {
            const long long height = h[st.back()];
            st.pop_back();
            const long long left = st.empty() ? 0 : st.back() + 1;
            const long long width = i - left;
            ans = max(ans, height * width);
        }

        st.push_back(i);
    }

    cout << ans << "\n";
    return 0;
}
