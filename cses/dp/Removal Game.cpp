#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<ll>> dp(n, vector<ll>(n, -1));

  for (int i = 0; i < n; i++)
    dp[i][i] = a[i];

  for (int i = 0; i < n - 1; i++)
    dp[i][i + 1] = max(a[i], a[i + 1]);

  for (int len = 3; len <= n; len++) {
    for (int i = 0; i + len - 1 < n; i++) {
      int j = i + len - 1;

      dp[i][j] = max(a[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                     a[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
    }
  }

  cout << dp[0][n - 1] << endl;
}

int main() {
  fastIO();
  solve();

  return 0;
}