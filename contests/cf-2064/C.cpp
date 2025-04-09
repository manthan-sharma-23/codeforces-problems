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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<ll> pref(n + 1, 0), suff(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1];

    if (a[i] >= 0)
      pref[i] += a[i];
  }

  suff[n] = a[n] < 0 ? abs(a[n]) : 0;
  for (int i = n - 1; i > 0; i--) {
    suff[i] = suff[i + 1];

    if (a[i] < 0)
      suff[i] += abs(a[i]);
  }

  ll maxi = 0;

  for (int i = 1; i <= n; i++) {
    maxi = max<ll>(maxi, pref[i] + suff[i]);
  }

  cout << maxi << endl;
}

int main() {
  fastIO();

  tc solve();

  return 0;
}