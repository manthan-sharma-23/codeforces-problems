#include <bits/stdc++.h>
// manthan's code

#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
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

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1), b(n + 1), hash(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  for (int i = 1; i <= n; i++)
    hash[a[i]] = i;

  int countSame = 0;

  for (int i = 1; i <= n; i++) {
    int ai = a[i], bi = b[i];
    int aj = a[hash[bi]], bj = b[hash[bi]];

    if (ai == bi) {
      if (n % 2 == 0 || countSame == 1) {
        cout << -1 << endl;
        return;
      } else {
        countSame = 1;
      }
    }

    if (ai != bj || aj != bi) {
      cout << -1 << endl;
      return;
    }
  }

  int i = 1, j = n;
  vector<pair<int, int>> res;

  while (i <= j) {
    if (a[i] == b[i] && i != (n / 2 + 1)) {
      hash[a[n / 2 + 1]] = i;
      hash[a[i]] = n / 2 + 1;
      swap(a[i], a[n / 2 + 1]);
      swap(b[i], b[n / 2 + 1]);
      res.push_back({i, n / 2 + 1});
      continue;
    }
    int posToCorrespoding = hash[b[i]];

    if (posToCorrespoding != j) {
      res.push_back({posToCorrespoding, j});
      hash[a[posToCorrespoding]] = j;
      hash[a[j]] = posToCorrespoding;
      swap(a[j], a[posToCorrespoding]);
      swap(b[j], b[posToCorrespoding]);
    }

    i++, j--;
  }

  if (res.size() > n) {
    cout << -1 << endl;
    return;
  }

  cout << res.size() << endl;
  for (auto it : res) {
    cout << it.first << " " << it.second << endl;
  }
}

int main() {
  fastIO();

  tc solve();

  return 0;
}