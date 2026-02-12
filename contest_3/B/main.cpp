#include <iostream>
#include <vector>


std::vector<int> swap_max_min(std::vector<int> v) {
    int min_val = v[0];
    int max_val = v[0];
    int min_idx = 0;
    int max_idx = 0;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < min_val) {
            min_val = v[i];
            min_idx = i;
        }
        if (v[i] > max_val) {
            max_val = v[i];
            max_idx = i;
        }
    }

    std::swap(v[min_idx], v[max_idx]);

    return v;
}
using std::vector;

int main() {
    vector<int> v;
    int a;

    while (std::cin >> a) {
        v.push_back(a);
    }

    v = swap_max_min(v);

    for (int el : v) {
        std::cout << el << ' ';
    }

    return 0;
}