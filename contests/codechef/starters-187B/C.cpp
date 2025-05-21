
#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 200005;

int dp[MAXN];

// Precompute dp[]
void precompute_dp() {
  dp[0] = 1;
  dp[1] = 2;
  dp[2] = 3;
  for (int i = 3; i < MAXN; ++i) {
    dp[i] = (dp[i - 1] + dp[i - 3]) % MOD;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute_dp();

  int T;
  cin >> T;
  while (T--) {
    int N;
    string S;
    cin >> N >> S;

    long long ans = 1;
    int i = 0;

    while (i < N) {
      int j = i;
      while (j + 1 < N && S[j] != S[j + 1]) {
        ++j;
      }
      int len = j - i + 1;

      if (len >= 4) {
        int M = len - 3;
        ans = (ans * dp[M]) % MOD;
      }

      i = j + 1;
    }

    cout << ans << '\n';
  }

  return 0;
}