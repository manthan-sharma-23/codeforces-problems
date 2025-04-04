#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

const int N_LARGE = 500001;
vector<ll> fact(N_LARGE + 1);

void compute_factorials() {
  fact[0] = 1;
  for (int i = 1; i <= N_LARGE; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
}

ll mod_expo(ll base, ll exp, ll mod) {
  ll result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

ll mod_inv(ll a, ll mod) { return mod_expo(a, mod - 2, mod); }

void solve() {
  vector<int> c(27, 0);
  c[0] = -1;
  ll n = 0;
  for (int i = 1; i <= 26; i++) {
    cin >> c[i];
    n += c[i];
  }

  if (n > N_LARGE) {
    cout << "0\n";
    return;
  }

  int even = n / 2;
  int odd = n - even;

  vector<vector<ll>> dp(27, vector<ll>(even + 1, 0));
  for (int i = 0; i <= 26; i++)
    dp[i][0] = 1;

  for (int i = 1; i <= 26; i++) {
    for (int j = 1; j <= even; j++) {
      dp[i][j] = dp[i - 1][j];
      if (c[i] > 0 && c[i] <= j) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - c[i]]) % MOD;
      }
    }
  }

  ll ans = dp[26][even];
  ans = (ans * fact[even] % MOD) * fact[odd] % MOD;

  for (int i = 1; i <= 26; i++) {
    if (c[i] > 0) {
      ans = (ans * mod_inv(fact[c[i]], MOD)) % MOD;
    }
  }

  cout << ans << endl;
}

int main() {
  compute_factorials();
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
