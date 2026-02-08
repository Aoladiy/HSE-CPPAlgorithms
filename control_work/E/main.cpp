#include <iostream>
#include <vector>

std::vector<std::vector<int> > Transpose(const std::vector<std::vector<int> > &matrix) {
    const int n = static_cast<int>(matrix.size());
    const int m = n ? static_cast<int>(matrix[0].size()) : 0;

    std::vector<std::vector<int> > transposed(m, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int> > a(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }
    Transpose(a);
    return 0;
}
