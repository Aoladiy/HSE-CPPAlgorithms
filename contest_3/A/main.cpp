#include <algorithm>
#include <iostream>
#include <vector>


std::vector<int> min_max_index(const std::vector<int> &vec) {
    int min_val = vec[0];
    int max_val = vec[0];
    int min_idx = 0;
    int max_idx = 0;

    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] < min_val) {
            min_val = vec[i];
            min_idx = i;
        }
        if (vec[i] > max_val) {
            max_val = vec[i];
            max_idx = i;
        }
    }

    const int distance = abs(max_idx - min_idx) - 1;

    std::vector<int> result;
    result.push_back(min_val);
    result.push_back(max_val);
    result.push_back(distance);

    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    std::vector<int> ans = min_max_index(vec);
    for(int i = 0; i < 2; ++i) {
        std::cout << ans[i] << ' ';
    }

    std::cout << ans[2] << std::endl;

    return 0;
}