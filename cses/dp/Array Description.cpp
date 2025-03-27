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
  int n, m;

  cin >> n >> m;

  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));

  if (arr[0] > 0)
    dp[0][arr[0]] = 1;
  else
    for (int i = 1; i <= m; i++)
      dp[0][i] = 1;

  for (int i = 1; i < n; i++) {
    if (arr[i] == 0) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = (dp[i - 1][j] + ((j - 1) >= 0 ? dp[i - 1][j - 1] : 0) +
                    ((j + 1) <= m ? dp[i - 1][j + 1] : 0)) %
                   MOD;
      }
    } else {
      dp[i][arr[i]] =
          (dp[i - 1][arr[i]] + (arr[i] - 1 >= 0 ? dp[i - 1][arr[i] - 1] : 0) +
           (arr[i] + 1 <= m ? dp[i - 1][arr[i] + 1] : 0)) %
          MOD;
    }
  }

  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = (ans + dp[n - 1][i]) % MOD;
  }

  cout << ans << endl;
}

int main() {
  fastIO();
  solve();

  return 0;
}