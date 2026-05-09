#include <iostream>
#include <vector>
#include <string>

using namespace std;

const __int128 MAXVAL = (static_cast<__int128>(1) << 63) - 1;
const __int128 MINVAL = -(static_cast<__int128>(1) << 63);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    if (n == 0) {
        cout << "Incorrect String!\n";
        return 0;
    }

    string line;
    getline(cin, line);

    vector<long long> st;
    st.reserve(n);

    int i = 0;
    const int len = static_cast<int>(line.size());
    int token_count = 0;

    while (i < len) {
        while (i < len && line[i] == ' ') i++;
        if (i >= len) break;

        token_count++;

        bool is_op = false;
        if ((line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/') &&
            (i + 1 >= len || line[i + 1] == ' ')) {
            is_op = true;
        }

        if (is_op) {
            const char op = line[i++];
            if (st.size() < 2) {
                cout << "Incorrect String!\n";
                return 0;
            }
            const long long b = st.back();
            st.pop_back();
            const long long a = st.back();
            st.pop_back();

            __int128 result;
            if (op == '+') result = static_cast<__int128>(a) + b;
            else if (op == '-') result = static_cast<__int128>(a) - b;
            else if (op == '*') result = static_cast<__int128>(a) * b;
            else {
                if (b == 0) {
                    cout << "Incorrect String!\n";
                    return 0;
                }
                result = static_cast<__int128>(a) / b;
            }

            if (result < MINVAL || result > MAXVAL) {
                cout << "Incorrect String!\n";
                return 0;
            }
            st.push_back(static_cast<long long>(result));
        } else {
            long long num = 0;
            bool neg = false;
            if (line[i] == '-') {
                neg = true;
                i++;
            }
            while (i < len && line[i] != ' ') {
                num = num * 10 + (line[i++] - '0');
            }
            if (neg) num = -num;
            st.push_back(num);
        }
    }

    if (st.size() != 1) {
        cout << "Incorrect String!\n";
        return 0;
    }

    cout << st[0] << "\n";
    return 0;
}
