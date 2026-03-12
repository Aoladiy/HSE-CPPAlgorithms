#include <iostream>
#include <map>
using namespace std;

map<long long, long long> memo;

long long a(const long long n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (memo.contains(n)) return memo[n];

    long long result;
    if (n % 2 == 0) {
        const long long k = n / 2;
        result = a(k) + a(k - 1);
    } else {
        const long long k = (n - 1) / 2;
        result = a(k) - a(k - 1);
    }

    return memo[n] = result;
}

int main() {
    long long n;
    cin >> n;
    cout << a(n) << endl;

    return 0;
}
