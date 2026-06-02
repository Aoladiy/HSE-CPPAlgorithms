#include <iostream>
#include <vector>
#include <set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, P;
    std::cin >> N >> M >> P;

    std::vector<std::array<long long, 4> > passengers(N);
    std::vector<std::vector<int> > enter(P + 1), leave(P + 1);

    long long baseSum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> passengers[i][0] >> passengers[i][1]
                >> passengers[i][2] >> passengers[i][3];
        const long long b = passengers[i][1];
        const long long c = passengers[i][2];
        const long long d = passengers[i][3];
        baseSum += b * (d - c);
        enter[c].push_back(i);
        leave[d].push_back(i);
    }

    std::multiset<std::pair<long long, int> > seated, standing;
    long long seatedSum = 0;

    auto rebalance = [&]() {
        while (static_cast<int>(seated.size()) < M && !standing.empty()) {
            auto it = std::prev(standing.end());
            if (it->first <= 0) break;
            seatedSum += it->first;
            seated.insert(*it);
            standing.erase(it);
        }
        while (static_cast<int>(seated.size()) > M) {
            auto it = seated.begin();
            seatedSum -= it->first;
            standing.insert(*it);
            seated.erase(it);
        }
        if (!seated.empty() && !standing.empty()) {
            const auto minSeated = seated.begin();
            if (const auto maxStanding = std::prev(standing.end()); maxStanding->first > minSeated->first) {
                seatedSum -= minSeated->first;
                seatedSum += maxStanding->first;
                seated.insert(*maxStanding);
                standing.insert(*minSeated);
                seated.erase(minSeated);
                standing.erase(maxStanding);
            }
        }
    };

    auto addPassenger = [&](int idx) {
        long long gain = passengers[idx][0] - passengers[idx][1];
        standing.insert({gain, idx});
        rebalance();
    };

    auto removePassenger = [&](int idx) {
        long long gain = passengers[idx][0] - passengers[idx][1];
        const auto key = std::make_pair(gain, idx);
        if (const auto it = seated.find(key); it != seated.end()) {
            seatedSum -= it->first;
            seated.erase(it);
        } else {
            standing.erase(standing.find(key));
        }
        rebalance();
    };

    long long bonus = 0;

    for (int stop = 1; stop < P; stop++) {
        for (const int idx: enter[stop]) addPassenger(idx);
        for (const int idx: leave[stop]) removePassenger(idx);
        bonus += seatedSum;
    }

    std::cout << baseSum + bonus << "\n";
    return 0;
}
