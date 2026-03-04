#include <iostream>
#include <vector>
using namespace std;

static int stk[5001];
static int hist[5001];

int largestRectangle(const int m) {
    int maxArea = 0, top = -1;
    for (int i = 0; i <= m; i++) {
        const int h = (i == m) ? 0 : hist[i];
        while (top >= 0 && hist[stk[top]] > h) {
            const int height = hist[stk[top--]];
            const int width = (top < 0) ? i : i - stk[top] - 1;
            maxArea = max(maxArea, height * width);
        }
        stk[++top] = i;
    }
    return maxArea;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            hist[j] = x ? 0 : hist[j] + 1;
        }
        ans = max(ans, largestRectangle(m));
    }

    cout << ans << '\n';
    return 0;
}
