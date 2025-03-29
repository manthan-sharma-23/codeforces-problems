#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int INV2 = 500000004; // Modular inverse of 2 under MOD

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n;
  cin >> n;

  ll tSum = (ll)n * (n + 1) / 2;

  if (tSum % 2 != 0) {
    cout << 0 << endl;
    return;
  }

  ll target = tSum / 2;

  vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

  dp[0][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      if (j >= i) {
        dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % MOD;
      }
    }
  }

  cout << (ll)dp[n][target] * INV2 % MOD << endl;
}

int main() {
  fastIO();
  solve();
  return 0;
}