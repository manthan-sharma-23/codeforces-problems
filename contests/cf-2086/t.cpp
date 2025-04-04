#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define br cout << "\n"
#define ft first
#define sd second
#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define naivedyam                                                              \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL);
#define loop(i, a, b) for (int i = a; i < b; i++)
#define input(a, n)                                                            \
  for (int i = 0; i < n; i++)                                                  \
  cin >> a[i]
#define input_vec(vec, n)                                                      \
  for (int i = 0; i < n; i++) {                                                \
    int x;                                                                     \
    cin >> x;                                                                  \
    vec.push_back(x);                                                          \
  }
#define input_set(set, n)                                                      \
  for (int i = 0; i < n; i++) {                                                \
    int x;                                                                     \
    cin >> x;                                                                  \
    set.insert(x);                                                             \
  }
#define input_matrix(mat, n, m)                                                \
  for (int i = 0; i < n; i++) {                                                \
    for (int j = 0; j < m; j++) {                                              \
      int x;                                                                   \
      cin >> x;                                                                \
      mat[i][j] = x;                                                           \
    }                                                                          \
  }
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define log2(x) (64 - __builtin_clzll(x) - 1) // log2 in O(1) time
#define print_vec(a)                                                           \
  for (int i = 0; i < a.size(); i++)                                           \
    cout << a[i] << " ";
#define print(n) cout << n << endl;
#define print_matrix(mat, n, m)                                                \
  for (int i = 0; i < n; i++) {                                                \
    for (int j = 0; j < m; j++) {                                              \
      cout << mat[i][j] << " ";                                                \
    }                                                                          \
    cout << endl;                                                              \
  }

const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = LLONG_MAX >> 1;
const int MAXN = 1e7 + 1;

//.........Bit_Manipulation...........//
#define msb(mask) (63 - __builtin_clzll(mask)) /// 0 -> -1
#define lsb(mask) __builtin_ctzll(mask)        /// 0 -> 64
#define lusb(mask) __builtin_ctzll(~(mask))
#define cntsetbit(mask) __builtin_popcountll(mask)
#define checkbit(mask, bit) ((mask >> bit) & 1ll)
#define onbit(mask, bit) ((mask) | (1LL << (bit)))
#define offbit(mask, bit) ((mask) & ~(1LL << (bit)))
#define changebit(mask, bit) ((mask) ^ (1LL << bit))

vector<int> spf(MAXN);

void spf_sieve(vector<int> &spf) {
  spf[1] = 1;
  for (int i = 2; i < MAXN; i++) {
    spf[i] = i;
  }
  for (int i = 2; i * i < MAXN; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < MAXN; j += i) {
        if (spf[j] == j)
          spf[j] = i;
      }
    }
  }
}

int n, k;

using v = vector<int>;
using pr = pair<int, int>;
using mp = map<int, int>;
using um = unordered_map<int, int>;
using us = unordered_set<int>;
using st = set<int>;
using pq = priority_queue<int>;
using str = string;
using mt = multiset<int>;
using dq = deque<int>;
using vp = vector<pr>;
using matrix = vector<vector<int>>;

v sieve(int n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
  }
  v primes;
  loop(i, 2, n + 1) {
    if (is_prime[i])
      primes.push_back(i);
  }
  return primes;
}

int orofrange(int l, int r) {
  int ans = 0;
  for (int i = 31; ~i; --i) {
    if ((l & (1LL << i)) || (r & (1LL << i)) ||
        (l >> (i + 1)) != (r >> (i + 1))) {
      ans |= (1LL << i);
    }
  }
  return ans;
}

int modularExponentiation(int x, int y, int p) {
  int res = 1;
  x = x % p;
  if (x == 0) {
    if (y == 0)
      return 1;
    else
      return 0;
  }
  while (y > 0) {
    if (y & 1)
      res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}

int nCr(int n, int r) {
  if (r > n)
    return 0;
  if (r == 0 || r == n)
    return 1;
  int res = 1;
  r = min(r, n - r);
  for (int i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}

int NewtonSQRT(int n) {
  int x = n;
  int y = (x + 1) / 2;
  while (y < x) {
    x = y;
    y = (x + n / x) / 2;
  }
  if (x * x == n)
    return x;
  return -1;
}

vp factorize(int n) {
  vp fact;
  int i = spf[n];
  while (n > 1) {
    int cnt = 0;
    while (n % i == 0) {
      n /= i;
      cnt++;
    }
    fact.push_back({i, cnt});
    i = spf[n];
  }
  if (n > 1)
    fact.push_back({n, 1});
  return fact;
}

int mod(int a, int m = MOD2) { return a % m; }

template <class T> class Math {
public:
  vector<T> fact, invfact;
  Math() {}
  Math(int n) {
    fact.resize(n);
    invfact.resize(n);
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < n; i++) {
      fact[i] = mod(i * fact[i - 1]);
      invfact[i] = modinv(fact[i]);
    }
  }
  T modinv(T x, T m = MOD2) { return expo(x, m - 2, m); }
  T expo(T base, T exp, T m = MOD2) {
    T res = 1;
    while (exp) {
      if (exp & 1)
        res = mod(res * base, m);
      base = mod(base * base, m);
      exp >>= 1;
    }
    return res;
  }
  T choose(T n, T k) {
    if (k < 0 || k > n)
      return 0;
    T ans = fact[n];
    ans = mod(ans * invfact[n - k]);
    ans = mod(ans * invfact[k]);
    return ans;
  }
};

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

/*int phi(int n){
    vp fact = factorize(n);
    int ans = n;
    loop(i,0,fact.size()) ans -= ans/fact[i].ft;
    return ans;
}*/

v derangement(int n) {
  v ans;
  ans.push_back(0);
  ans.push_back(0);
  ans.push_back(1);
  loop(i, 3, n + 1) ans.push_back(
      ((i - 1) % MOD) * ((ans[i - 1] % MOD + ans[i - 2] % MOD) % MOD));
  return ans;
}

int extended_gcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = extended_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

signed main() {
  naivedyam Math<int> math(1e6);
  tc {
    v c;
    input_vec(c, 26);
    int sz = (accumulate(c.begin(), c.end(), 0ll) + 1) / 2;
    v dp(sz + 1, 0);
    dp[0] = 1;
    loop(i, 0, 26) {
      if (c[i]) {
        for (int j = sz - c[i]; j >= 0; j--)
          dp[c[i] + j] = (dp[c[i] + j] + dp[j]) % MOD2;
      }
    }
    int prod = 1, ans = dp[sz];
    loop(i, 0, 26) {
      prod *= math.fact[c[i]];
      prod %= MOD2;
    }
    ans *= math.modinv(prod);
    ans %= MOD2;
    ans *= math.fact[sz];
    ans %= MOD2;
    ans *= math.fact[accumulate(c.begin(), c.end(), 0ll) / 2];
    ans %= MOD2;
    print(ans)
  }
  return 0;
}