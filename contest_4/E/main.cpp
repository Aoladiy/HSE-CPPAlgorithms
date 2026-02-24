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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x: a) {
        std::cin >> x;
    }

    int m;
    std::cin >> m;
    std::vector<int> b(m);
    for (int &x: b) {
        std::cin >> x;
    }

    std::vector<int> result(n + m);
    merge(a.begin(), a.end(), b.begin(), b.end(), result.begin());

    for (int i = 0; i < n + m; i++) {
        std::cout << result[i];
        if (i < n + m - 1) {
            std::cout << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}
