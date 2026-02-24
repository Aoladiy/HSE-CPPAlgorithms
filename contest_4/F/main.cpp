#include <bits/stdc++.h>

void merge(
    std::vector<int>::iterator aBegin, const std::vector<int>::iterator aEnd,
    std::vector<int>::iterator bBegin, const std::vector<int>::iterator bEnd,
    std::vector<int>::iterator out
) {
    while (aBegin != aEnd && bBegin != bEnd) {
        if (*aBegin <= *bBegin) {
            *out = *aBegin;
            ++aBegin;
        } else {
            *out = *bBegin;
            ++bBegin;
        }
        ++out;
    }
    while (aBegin != aEnd) {
        *out = *aBegin;
        ++aBegin;
        ++out;
    }
    while (bBegin != bEnd) {
        *out = *bBegin;
        ++bBegin;
        ++out;
    }
}

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n), b(m), c(k);
    for (int &x: a) {
        std::cin >> x;
    }
    for (int &x: b) {
        std::cin >> x;
    }
    for (int &x: c) {
        std::cin >> x;
    }

    std::vector<int> temp(n + m);
    merge(a.begin(), a.end(), b.begin(), b.end(), temp.begin());

    std::vector<int> result(n + m + k);
    merge(temp.begin(), temp.end(), c.begin(), c.end(), result.begin());

    for (int i = 0; i < n + m + k; i++) {
        std::cout << result[i];
        if (i < n + m + k - 1) {
            std::cout << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}
