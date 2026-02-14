#include <iostream>
#include <vector>


std::vector<int> cur;

void generate(const int remaining, const int minVal) {
    if (remaining == 0) {
        for (int i = 0; i < static_cast<int>(cur.size()); i++) {
            if (i) std::cout << ' ';
            std::cout << cur[i];
        }
        std::cout << '\n';
        return;
    }
    for (int x = remaining; x >= minVal; x--) {
        cur.push_back(x);
        generate(remaining - x, x);
        cur.pop_back();
    }
}

int main() {
    int n;
    std::cin >> n;
    generate(n, 1);
    return 0;
}
