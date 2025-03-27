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

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= m; i++) {
    dp[0][i] = i;
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = i;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
    }
  }
}

int main() {
  fastIO();
  solve();

  return 0;
}