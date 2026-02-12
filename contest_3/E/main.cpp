#include <iostream>
#include <vector>
#include <set>


std::set<int> printed;

void print(const std::vector<int> &numbers, const int k) {
    std::vector<int> available;
    for (int i = 0; i < static_cast<int>(numbers.size()); i++) {
        if (!printed.contains(i)) {
            available.push_back(i);
        }
    }

    bool first = true;
    for (int i = 0; i < static_cast<int>(available.size()); i += k) {
        if (!first) std::cout << ' ';
        std::cout << numbers[available[i]];
        printed.insert(available[i]);
        first = false;
    }
    std::cout << '\n';
}

using std::string;
using std::cin;
using std::cout;
using std::vector;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &el: v) cin >> el;
    int q, k;
    cin >> q;
    while (q--) {
        cin >> k;
        print(v, k);
    }
}
