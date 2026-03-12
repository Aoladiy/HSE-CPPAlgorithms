#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector dist(n + 1, -1);
    vector parent(n + 1, -1);

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        const int x = q.front();
        q.pop();
        if (x == n) break;

        for (int ops[] = {x * 3, x * 2, x + 1}; int next: ops) {
            if (next <= n && dist[next] == -1) {
                dist[next] = dist[x] + 1;
                parent[next] = x;
                q.push(next);
            }
        }
    }

    vector<int> path;
    for (int v = n; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());

    cout << dist[n] << "\n";
    for (const int x: path) cout << x << " ";
    cout << "\n";

    return 0;
}
