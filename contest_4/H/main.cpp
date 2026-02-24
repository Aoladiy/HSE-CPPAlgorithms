#include <bits/stdc++.h>

int main() {
    std::vector<std::pair<int, int>> all;

    for (int type = 0; type < 4; ++type) {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            all.emplace_back(x, type);
        }
    }

    std::ranges::sort(all);

    std::vector count(4, 0);
    int covered = 0;
    int left = 0;
    int bestDiff = INT_MAX;
    int bestLeft = 0, bestRight = 0;

    for (int right = 0; right < static_cast<int>(all.size()); ++right) {
        const int type = all[right].second;
        if (count[type] == 0) {
            ++covered;
        }
        ++count[type];

        while (covered == 4) {
            if (const int diff = all[right].first - all[left].first; diff < bestDiff) {
                bestDiff = diff;
                bestLeft = left;
                bestRight = right;
            }
            const int leftType = all[left].second;
            --count[leftType];
            if (count[leftType] == 0) {
                --covered;
            }
            ++left;
        }
    }

    std::vector answer(4, -1);
    for (int i = bestLeft; i <= bestRight; ++i) {
        if (const int t = all[i].second; answer[t] == -1) {
            answer[t] = all[i].first;
        }
    }

    std::cout << answer[0] << ' ' << answer[1] << ' ' << answer[2] << ' ' << answer[3] << '\n';

    return 0;
}