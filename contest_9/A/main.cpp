#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> q;

    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;

        if (op == '+') {
            int x;
            cin >> x;
            q.push_back(x);
        } else if (op == '*') {
            int x;
            cin >> x;
            const int pos = (static_cast<int>(q.size()) + 1) / 2;
            q.insert(q.begin() + pos, x);
        } else {
            cout << q.front() << "\n";
            q.pop_front();
        }
    }

    return 0;
}
