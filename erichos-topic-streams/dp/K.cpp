#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;

ll dp[2001][2001];

ll f(int last, int i, int k, int n) {
  if (i > k)
    return 1;
  if (dp[last][i] != -1)
    return dp[last][i];

  ll moves = 0;
  for (int b = last; b <= n; b += last) {
    moves = (moves + f(b, i + 1, k, n)) % MOD;
  }

  return dp[last][i] = moves;
}

void solve() {
  int n, k;
  cin >> n >> k;

  memset(dp, -1, sizeof(dp));
  cout << f(1, 1, k, n) << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}
