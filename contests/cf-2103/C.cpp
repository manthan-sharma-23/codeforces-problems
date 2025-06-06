#include <bits/stdc++.h>
// manthan's code
using namespace std;
#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2, custom_hash>
#define hash_set(T) unordered_set<T>

using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vll = vector<ll>;
using vi = vector<int>;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

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

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  ll x1, y1;
  ll gcd = extended_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return gcd;
}

ll mod_inv(ll a, ll mod) {
  ll x, y;
  ll g = extended_gcd(a, mod, x, y);
  if (g != 1)
    return -1;
  return (x % mod + mod) % mod;
}

ll ncr_mod(int n, int r) {
  if (r > n)
    return 0;
  return (fact[n] * mod_inv(fact[r], MOD) % MOD) * mod_inv(fact[n - r], MOD) %
         MOD;
}

ll ncr(int n, int r) {
  if (r > n)
    return 0;
  return fact[n] / (fact[r] * fact[n - r]);
}

void solve() {
  int n, k;
  cin >> n >> k;

  vi a(n);
  each(it, a) cin >> it;

  vi b(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    b[i] = (a[i - 1] > k ? -1 : 1);
  }

  vi pref(n + 1, 0), suff(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + b[i];
  }

  suff[n] = b[n];
  for (int i = n - 1; i >= 1; i--) {
    suff[i] = suff[i + 1] + b[i];
  }

  each(it, pref) cout << it << " ";
  cout << endl;

  int fzp = 0, szp = 0;
  for (int i = 1; i <= n; i++) {
    if (pref[i] >= 0) {
      if (fzp == 0)
        fzp = i;
      else if (szp == 0)
        szp = i;
    }
  }

  int fzs = 0, szs = 0;
  for (int i = n; i >= 1; i--) {
    if (suff[i] >= 0) {
      if (fzs == 0)
        fzs = i;
      else if (szs == 0)
        szs = i;
    }
  }

  cout << fzp << " " << szp << " " << fzs << " " << szs << " " << endl;
  if (fzp != 0 && fzs != 0 && fzp < fzs) {
    cout << "YES" << endl;
    return;
  }

  if (szp != 0 && szp < n) {
    cout << "YES" << endl;
    return;
  }

  if (szs != 0 && szs > 1) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
}

int main() {
  fastIO();

  tc solve();

  return 0;
}
