#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> first, second;

    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        first.push(x);
    }
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        second.push(x);
    }

    int moves = 0;
    constexpr int MAX_MOVES = 1000000;

    while (!first.empty() && !second.empty() && moves < MAX_MOVES) {
        int a = first.front();
        first.pop();
        int b = second.front();
        second.pop();
        moves++;

        bool first_wins;
        if (a == 0 && b == 9)
            first_wins = true;
        else if (b == 0 && a == 9)
            first_wins = false;
        else
            first_wins = a > b;

        if (first_wins) {
            first.push(a);
            first.push(b);
        } else {
            second.push(a);
            second.push(b);
        }
    }

    if (moves == MAX_MOVES) {
        cout << "botva\n";
    } else if (second.empty()) {
        cout << "first " << moves << "\n";
    } else {
        cout << "second " << moves << "\n";
    }

    return 0;
}
