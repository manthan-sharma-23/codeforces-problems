#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  const int mod = 1e9 + 7;
  int n;
  cin >> n;

  vector<int> dp(n + 1, 0);

  dp[0] = 1;

  for (int i = 1; i <= n; i++)
    for (int j = i - 1; ((i - j) <= 6) && (j >= 0); j--)
      dp[i] = (dp[i] + dp[j]) % mod;

  cout << dp[n] << endl;
}

int main() {
  fastIO();
  solve();

  return 0;
}