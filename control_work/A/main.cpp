#include <iostream>
#include <vector>

int main() {
    int M, N, K;
    std::cin >> M >> N >> K;

    // -1 = мина, иначе число мин вокруг
    std::vector<std::vector<int>> a(M, std::vector<int>(N, 0));

    for (int t = 0; t < K; ++t) {
        int p, q;
        std::cin >> p >> q;
        --p; --q;               // в 0-based
        a[p][q] = -1;
    }

    const int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
    const int dy[8] = {-1, 0, 1,-1,1,-1,0,1};

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i][j] == -1) continue;

            int cnt = 0;
            for (int k = 0; k < 8; ++k) {
                int ni = i + dx[k], nj = j + dy[k];
                if (0 <= ni && ni < M && 0 <= nj && nj < N && a[ni][nj] == -1) {
                    ++cnt;
                }
            }
            a[i][j] = cnt;
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j) std::cout << ' ';
            if (a[i][j] == -1) std::cout << '*';
            else std::cout << a[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}
