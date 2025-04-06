#include <bits/stdc++.h>
// manthan's code

#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
#define inputInt(x)                                                            \
  int x;                                                                       \
  cin >> x;
using namespace std;

void print1D(const vector<int> &v) {
  each(x, v) cout << x << " ";
  cout << endl;
}
void print2D(const vector<vector<int>> &v) {
  each(e, v) {
    each(x, e) cout << x << " ";
    cout << endl;
  }
  cout << endl;
}

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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  long long ans = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ans += a[i];
    cnt += (a[i] & 1);
  }
  if (!cnt || cnt == n) {
    cout << *max_element(a.begin(), a.end()) << '\n';
  } else {
    cout << ans - cnt + 1 << '\n';
  }
}

int main() {
  fastIO();

  tc solve();

  return 0;
}