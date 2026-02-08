#include <iostream>
#include <vector>

char digit_to_char(const int d) {
    if (d < 10) {
        return static_cast<char>('0' + d);
    }
    return static_cast<char>('a' + (d - 10));
}

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> s(N, K - 1);

    while (true) {
        for (int i = 0; i < N; ++i) {
            std::cout << digit_to_char(s[i]);
        }
        std::cout << '\n';

        int pos = N - 1;
        while (pos >= 0 && s[pos] == 0) {
            s[pos] = K - 1;
            --pos;
        }
        if (pos < 0) {
            break;
        }
        --s[pos];
    }

    return 0;
}
