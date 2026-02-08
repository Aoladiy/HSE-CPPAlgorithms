#include <iostream>
#include <limits>

int main() {
    int d, h, m;
    std::cin >> d >> h >> m;

    int N;
    std::cin >> N;

    constexpr int MIN_PER_DAY = 1440;

    const int curDay = d - 1;
    const int curMinDay = h * 60 + m;

    int best = std::numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        int w, ah, am;
        std::cin >> w >> ah >> am;
        const int alarmMinDay = ah * 60 + am;

        int next;

        if (w == 0) {
            const int dayIndex = curDay + (alarmMinDay < curMinDay ? 1 : 0);
            next = dayIndex * MIN_PER_DAY + alarmMinDay;
        } else {
            const int targetDay = w - 1;
            int dayIndex = targetDay;

            if (targetDay < curDay || (targetDay == curDay && alarmMinDay < curMinDay)) {
                dayIndex += 7;
            }
            next = dayIndex * MIN_PER_DAY + alarmMinDay;
        }

        if (next < best) best = next;
    }

    const int bestDay = (best / MIN_PER_DAY) % 7;
    const int bestMinDay = best % MIN_PER_DAY;
    const int bestH = bestMinDay / 60;
    const int bestM = bestMinDay % 60;

    std::cout << (bestDay + 1) << ' ' << bestH << ' ' << bestM;
    return 0;
}
