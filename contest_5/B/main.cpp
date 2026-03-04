#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::cout << a[n / 2] << std::endl;
    return 0;
}
