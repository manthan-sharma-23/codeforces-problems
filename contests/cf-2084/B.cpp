#include <bits/stdc++.h>
using namespace std;

#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)

constexpr int MOD = 1e9 + 7;
constexpr int MAX_FACTORIAL = 500001;
constexpr int MAX_SIEVE = 1e6;

typedef long long ll;
typedef unsigned long long ull;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

vector<ll> fact(MAX_FACTORIAL);
void compute_factorials() {
  fact[0] = 1;
  for (int i = 1; i < MAX_FACTORIAL; i++) {  
    fact[i] = (1LL * fact[i - 1] * i) % MOD; 
  }
}

vector<bool> isPrime(MAX_SIEVE + 1, 1);
void sieve() {
  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i <= sqrt(MAX_SIEVE); i++) { 
    if (isPrime[i]) {
      for (int j = i * i; j <= MAX_SIEVE; j += i) {
        isPrime[j] = 0;
      }
    }
  }
}

template <typename T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }

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

  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll mini = *min_element(a.begin(), a.end());
  ll cnt = count(a.begin(), a.end(), mini); 

  if (cnt > 1) {
    cout << "YES" << endl;
    return;
  }

  ll gc = 0;
  each(v, a) {
    if (v != mini && v % mini == 0) {
      gc = gcd(v, gc);
    }
  }

  cout << (gc == mini ? "YES" : "NO") << endl; 
}

int main() {
  fastIO();
  tc solve();
  return 0;
}
