#include <iostream>
#include <map>

long long k;
std::map<long long, long long> memo;

long long solve(const long long n) {
    if (n <= k) return 1;
    if (memo.contains(n)) return memo[n];
    return memo[n] = solve((n + 1) / 2) + solve(n / 2);
}

int main() {
    long long n;
    std::cin >> n >> k;
    std::cout << solve(n) << std::endl;
    return 0;
}
