#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    vector<vector<int> > items(4);
    for (int t = 0; t < 4; t++) {
        int n;
        cin >> n;
        items[t].resize(n);
        for (int i = 0; i < n; i++) cin >> items[t][i];
        ranges::sort(items[t]);
    }

    vector<pair<int, int> > all;
    for (int t = 0; t < 4; t++)
        for (int x: items[t])
            all.emplace_back(x, t);
    ranges::sort(all);

    int cnt[4] = {};
    int have = 0;
    int left = 0;
    int bestRange = INT_MAX;
    int ansLeft = 0, ansRight = 0;

    for (int right = 0; right < static_cast<int>(all.size()); right++) {
        const int cat = all[right].second;
        if (cnt[cat] == 0) have++;
        cnt[cat]++;

        while (have == 4) {
            if (const int range = all[right].first - all[left].first; range < bestRange) {
                bestRange = range;
                ansLeft = left;
                ansRight = right;
            }
            const int lcat = all[left].second;
            cnt[lcat]--;
            if (cnt[lcat] == 0) have--;
            left++;
        }
    }

    int ans[4] = {-1, -1, -1, -1};
    for (int i = ansLeft; i <= ansRight; i++) {
        if (const int cat = all[i].second; ans[cat] == -1)
            ans[cat] = all[i].first;
    }

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << '\n';
    return 0;
}
