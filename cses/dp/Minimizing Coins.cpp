#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n, x;
  cin >> n >> x;

  vector<int> coins(n);

  for (int i = 0; i < n; i++)
    cin >> coins[i];

  vector<int> dp(x + 1, 1e8);

  dp[0] = 0;

  for (int i = 1; i <= x; i++) {
    for (const int &coin : coins) {
      if (i >= coin)
        dp[i] = min(dp[i], 1 + dp[i - coin]);
    }
  }

  cout << (dp[x] == 1e8 ? -1 : dp[x]) << endl;
}

int main() {
  fastIO();
  solve();

  return 0;
}