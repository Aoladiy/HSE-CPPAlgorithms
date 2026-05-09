#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> m(n);
    for (int i = 0; i < n; i++)
        cin >> m[i];

    vector<long long> sum_left(n), sum_right(n);

    {
        stack<pair<long long, long long> > st;
        long long cur_sum = 0;
        for (int i = 0; i < n; i++) {
            long long cnt = 1;
            while (!st.empty() && st.top().first >= m[i]) {
                auto [val, c] = st.top();
                st.pop();
                cur_sum += (m[i] - val) * c;
                cnt += c;
            }
            st.emplace(m[i], cnt);
            cur_sum += m[i];
            sum_left[i] = cur_sum;
        }
    }

    {
        stack<pair<long long, long long> > st;
        long long cur_sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            long long cnt = 1;
            while (!st.empty() && st.top().first >= m[i]) {
                auto [val, c] = st.top();
                st.pop();
                cur_sum += (m[i] - val) * c;
                cnt += c;
            }
            st.emplace(m[i], cnt);
            cur_sum += m[i];
            sum_right[i] = cur_sum;
        }
    }

    long long best = -1;
    int best_p = 0;
    for (int p = 0; p < n; p++) {
        if (const long long total = sum_left[p] + sum_right[p] - m[p]; total > best) {
            best = total;
            best_p = p;
        }
    }

    vector<long long> ans(n);
    long long cur = m[best_p];
    for (int i = best_p; i >= 0; i--) {
        cur = min(cur, m[i]);
        ans[i] = cur;
    }
    cur = m[best_p];
    for (int i = best_p + 1; i < n; i++) {
        cur = min(cur, m[i]);
        ans[i] = cur;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];

    return 0;
}
