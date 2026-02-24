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

void mergeSort(const std::vector<int>::iterator begin, const std::vector<int>::iterator end) {
    const long long size = end - begin;
    if (size <= 1) {
        return;
    }

    const auto mid = begin + size / 2;

    mergeSort(begin, mid);
    mergeSort(mid, end);

    std::vector<int> temp(size);
    merge(begin, mid, mid, end, temp.begin());

    for (int i = 0; i < size; i++) {
        *(begin + i) = temp[i];
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x: a) {
        std::cin >> x;
    }

    mergeSort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        std::cout << a[i];
        if (i < n - 1) {
            std::cout << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}
