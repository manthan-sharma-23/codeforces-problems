#include <climits>
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
  string s, z;

  cin >> s;
  cin >> z;

  int n = s.length(), m = z.length();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));

  for (int i = 0; i <= n; i++)
    dp[i][0] = i;

  for (int i = 0; i <= m; i++)
    dp[0][i] = i;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == z[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] =
            min(1 + dp[i - 1][j], min(1 + dp[i][j - 1], 1 + dp[i - 1][j - 1]));
      }
    }
  }

  cout << dp[n][m] << endl;
}

int main() {
  fastIO();
  solve();

  return 0;
}