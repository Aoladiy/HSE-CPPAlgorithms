#include <iostream>
#include <vector>
#include <map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N, M;
    std::cin >> N >> M;

    std::map<long long, long long> byStart;
    byStart[1] = N;

    std::vector<std::pair<long long, long long> > alloc(M + 1, {-1, -1});

    for (int i = 1; i <= M; i++) {
        long long val;
        std::cin >> val;

        if (val > 0) {
            const long long K = val;
            long long foundStart = -1, foundEnd = -1;
            for (auto &[l, r]: byStart) {
                if (r - l + 1 >= K) {
                    foundStart = l;
                    foundEnd = r;
                    break;
                }
            }
            if (foundStart == -1) {
                std::cout << -1 << "\n";
                continue;
            }
            alloc[i] = {foundStart, foundStart + K - 1};
            byStart.erase(foundStart);
            if (foundStart + K <= foundEnd) {
                byStart[foundStart + K] = foundEnd;
            }
            std::cout << foundStart << "\n";
        } else {
            const long long T = -val;
            if (alloc[T].first == -1) continue;

            const long long l = alloc[T].first;
            const long long r = alloc[T].second;
            alloc[T] = {-1, -1};

            long long newL = l, newR = r;

            if (auto rightIt = byStart.find(r + 1); rightIt != byStart.end()) {
                newR = rightIt->second;
                byStart.erase(rightIt);
            }

            if (l > 1) {
                if (auto leftIt = byStart.upper_bound(l - 1); leftIt != byStart.begin()) {
                    --leftIt;
                    if (leftIt->second == l - 1) {
                        newL = leftIt->first;
                        byStart.erase(leftIt);
                    }
                }
            }

            byStart[newL] = newR;
        }
    }

    return 0;
}
