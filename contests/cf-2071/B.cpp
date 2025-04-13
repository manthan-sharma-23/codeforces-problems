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

const int MAX_FACTORIAL =
    100005; // Reduce size to avoid unnecessary memory usage
vector<ll> fact(MAX_FACTORIAL + 1, 1);

void compute_factorials() {
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

bool isPerfectSquare(ll n) {
  if (n < 0)
    return false;
  ll sqrtN = sqrt(n);
  return sqrtN * sqrtN == n;
}

void solve() {
  int n;
  cin >> n;

  ll sum = (1LL * n * (n + 1)) / 2;
  if (isPerfectSquare(sum)) {
    cout << -1 << endl;
    return;
  }

  vector<int> numbers(n);
  iota(numbers.begin(), numbers.end(), 1); // Fills numbers from 1 to n

  for (int i = n - 2; i >= 0; i--) {
    ll partialSum = (1LL * (i + 1) * (i + 2)) / 2;
    if (isPerfectSquare(partialSum)) {
      swap(numbers[i], numbers[i + 1]);
    }
  }

  each(v, numbers) { cout << v << " "; }
  cout << endl;
}

int main() {
  fastIO();
  tc solve();
  return 0;
}
