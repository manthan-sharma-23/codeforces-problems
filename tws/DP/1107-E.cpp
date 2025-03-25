#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> a(n + 1, 0);
  for (int i = 1; i <= n; i++)
    a[i] = n;

  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    dp[i][i] = a[1];
  }

  for (int len = 2; len <= n; len++) {
    for (int i = 0; i + len - 1 < n; i++) {
      int j = i + len - 1;

      int occi = 0;

      for (int k = i; k < j; k++) {
        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
        if (s[i] == s[j]) {
          dp[i][j] -= (a[occi] + a[1]);
          dp[i][j] += a[occi + 1];
        }
      }
    }
  }
  cout << dp[0][n - 1] << endl;
}

int main() {
  solve();

  return 0;
}