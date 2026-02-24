#include <bits/stdc++.h>

void putMaxAtEnd(const std::vector<int>::iterator begin, const std::vector<int>::iterator end) {
    if (begin == end) {
        return;
    }
    auto maxIt = begin;
    for (auto it = begin + 1; it != end; ++it) {
        if (*it > *maxIt) {
            maxIt = it;
        }
    }
    std::swap(*maxIt, *(end - 1));
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x: a) {
        std::cin >> x;
    }

    for (int i = n; i > 1; i--) {
        putMaxAtEnd(a.begin(), a.begin() + i);
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}
