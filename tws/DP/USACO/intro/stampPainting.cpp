#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

ll n, m, k;
vector<ll> memo;

ll f(int i) {
    if (i > n) return 1;  // base case: done covering the canvas
    if (memo[i] != -1) return memo[i];

    ll ways = 0;
    // Try placing a stamp ending at j, covering [j - k + 1, j]
    for (int j = i + k - 1; j <= n; ++j) {
        // The stamp covers positions from j - k + 1 to j
        // And we recursively go from j + 1
        ways = (ways + (m * f(j + 1)) % MOD) % MOD;
    }

    return memo[i] = ways;
}

int main() {
    cin >> n >> m >> k;
    memo.assign(n + 2, -1);
    cout << f(1) << "\n";
    return 0;
}
