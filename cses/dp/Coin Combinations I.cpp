#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

const int MOD = 1e9 + 7;
void solve() {
  int n, x;

  cin >> n >> x;

  vector<int> coins(n);

  for (int i = 0; i < n; i++)
    cin >> coins[i];

  vector<int> dp(x + 1, 0);

  dp[0] = 1;

  for (int i = 1; i <= x; i++) {
    for (const int &coin : coins) {
      if (i >= coin) {
        dp[i] = (dp[i] + dp[i - coin]) % MOD;
      }
    }
  }

  cout << dp[x] << endl;
}

int main() {
  fastIO();
  solve();

  return 0;
}