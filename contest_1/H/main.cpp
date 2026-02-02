#include <iostream>

int main() {
    int N, K, M;
    std::cin >> N >> K >> M;

    if (N < K || K < M) {
        std::cout << 0;
        return 0;
    }

    int total_parts_done = 0;

    while (N >= K) {
        int templates = N / K;
        int remains_after_templates = N % K;

        int parts_per_template = K / M;
        int remains_per_template = K % M;

        total_parts_done += templates * parts_per_template;

        N = remains_after_templates + templates * remains_per_template;
    }

    std::cout << total_parts_done;
    return 0;
}
