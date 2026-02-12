#include <iostream>
#include <vector>


int min_element(std::vector<int> v) {
    int min_odd = 0;
    bool found = false;

    for (const int i : v) {
        if (i % 2 != 0) {
            if (!found) {
                min_odd = i;
                found = true;
            } else if (i < min_odd) {
                min_odd = i;
            }
        }
    }

    return found ? min_odd : 0;
}

using std::vector;

int main() {
    vector<int> v;
    int a;

    while (std::cin >> a) {
        v.push_back(a);
    }

    std::cout << min_element(v);

    return 0;
}