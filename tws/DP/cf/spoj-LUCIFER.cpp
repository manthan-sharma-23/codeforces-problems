#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_SIEVE = 200;
vector<bool> isPrime(MAX_SIEVE + 1, true);

// 1) precompute primes up to MAX_SIEVE=200
void sieve() {
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i <= MAX_SIEVE; i++) {
    if (!isPrime[i])
      continue;
    for (int j = i * i; j <= MAX_SIEVE; j += i)
      isPrime[j] = false;
  }
}

// dp[pos][tight][sum_even][sum_odd]
//   pos          = current index in the digit‐string (0..len-1)
//   tight        = are we still on the prefix bound?
//   sum_even     = sum of digits in even positions (from the right, 1‑based)
//   sum_odd      = sum of digits in odd positions  (from the right, 1‑based)
static ll dp[20][2][180][180];

ll go(int pos, bool tight, int se, int so, const string &s) {
  if (pos == s.size()) {
    int diff = se - so;
    return (diff > 1 && isPrime[diff]) ? 1LL : 0LL;
  }
  ll &res = dp[pos][tight][se][so];
  if (res != -1)
    return res;

  res = 0;
  int lim = tight ? s[pos] - '0' : 9;
  for (int d = 0; d <= lim; d++) {
    bool nt = tight && (d == lim);
    int position_from_right = (int)s.size() - pos;
    if (position_from_right % 2 == 0)
      res += go(pos + 1, nt, se + d, so, s);
    else
      res += go(pos + 1, nt, se, so + d, s);
  }
  return res;
}

ll count_upto(ll x) {
  string s = to_string(x);
  memset(dp, -1, sizeof(dp));
  return go(0, true, 0, 0, s);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  sieve();
  int T;
  cin >> T;
  while (T--) {
    ll l, r;
    cin >> l >> r;
    cout << count_upto(r) - count_upto(l - 1) << "\n";
  }
  return 0;
}
