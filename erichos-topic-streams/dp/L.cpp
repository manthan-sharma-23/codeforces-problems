#include <bits/stdc++.h>
// manthan's code

#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2>
#define hash_set(T) unordered_set<T>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
const int MAX_FACTORIAL = 500001;
vector<ll> fact(MAX_FACTORIAL + 1);
void compute_factorials() {
  fact[0] = 1;
  for (int i = 1; i <= MAX_FACTORIAL; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
}

const int MAX_SIEVE = 1e6;
vector<bool> isPrime(MAX_SIEVE + 1, 1);
void sieve() {
  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i * i <= MAX_SIEVE; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAX_SIEVE; j += i) {
        isPrime[j] = 0;
      }
    }
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

ll _sqrt(ll n) {
  if (n == 0 || n == 1)
    return n;

  ll low = 1, high = n, ans = 0;
  while (low <= high) {
    ll mid = low + (high - low) / 2;
    if (mid * mid == n)
      return mid;
    else if (mid * mid < n) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

ll nCrMod(int n, int r) {
  if (r > n)
    return 0;
  return (fact[n] * mod_inv(fact[r], MOD) % MOD) * mod_inv(fact[n - r], MOD) %
         MOD;
}

ll nCr(int n, int r) {
  if (r > n)
    return 0;
  return fact[n] / (fact[r] * fact[n - r]);
}

void solve() {
  int n, k;
  cin >> n;

  vector<vector<int>> requests(n + 1, vector<int>(3, 0));
  for (int i = 1; i <= n; i++) {
    cin >> requests[i][0];
    cin >> requests[i][1];
    requests[i][2] = i;
  }

  sort(requests.begin() + 1, requests.end());

  cin >> k;
  vector<vector<int>> tables(k + 1, vector<int>(2, 0));
  for (int i = 1; i <= k; i++) {
    cin >> tables[i][0];
    tables[i][1] = i;
  }

  sort(tables.begin() + 1, tables.end());

  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = dp[i - 1][j];
      if (requests[i][0] <= tables[j][0]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + requests[i][1]);
      }
    }
  }

  vector<vector<int>> res;
  int i = n, j = k;

  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else if (requests[i][0] <= tables[j][0] &&
               dp[i][j] == dp[i - 1][j - 1] + requests[i][1]) {
      res.push_back({requests[i][2], tables[j][1]});
      i--;
      j--;
    } else {
      i--;
    }
  }

  cout << res.size() << " " << dp[n][k] << "\n";
  each(pair, res) cout << pair[0] << " " << pair[1] << "\n";
}

int main() {
  fastIO();

  solve();

  return 0;
}
