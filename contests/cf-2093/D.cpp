#include <bits/stdc++.h>
// manthan's code

#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
#define minHeap(T) priority_queue<T, vector<T>, greater<T>>
#define maxHeap(T) priority_queue<T>
#define hashMap(T1, T2) unordered_map<T1, T2>
#define hashSet(T) unordered_set<T>

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

int n, q;
ll f(int level, int row, int col) {
  if (level == 1) {
    if (row == 1 && col == 1)
      return 1;
    if (row == 2 && col == 2)
      return 2;
    if (row == 2 && col == 1)
      return 3;
    return 4;
  }
  int half = 1 << (level - 1);
  ll baseSize = 1LL << (2 * (level - 1));

  if (row <= half && col <= half)
    return f(level - 1, row, col);
  if (row > half && col > half)
    return baseSize + f(level - 1, row - half, col - half);
  if (row > half && col <= half)
    return 2 * baseSize + f(level - 1, row - half, col);

  return 3 * baseSize + f(level - 1, row, col - half);
}

pair<int, int> d(int level, ll index) {
  if (level == 1) {
    if (index == 1)
      return {1, 1};
    if (index == 2)
      return {2, 2};
    if (index == 3)
      return {2, 1};
    return {1, 2};
  }
  int half = 1 << (level - 1);
  ll baseSize = 1LL << (2 * (level - 1));

  if (index <= baseSize) {
    auto p = d(level - 1, index);
    return {p.first, p.second};
  }
  if (index <= 2 * baseSize) {
    auto p = d(level - 1, index - baseSize);
    return {p.first + half, p.second + half};
  }
  if (index <= 3 * baseSize) {
    auto p = d(level - 1, index - 2 * baseSize);
    return {p.first + half, p.second};
  }
  auto p = d(level - 1, index - 3 * baseSize);
  return {p.first, p.second + half};
}
void solve() {
  cin >> n >> q;

  ll size = pow(2, n);
  ll largestNum = pow(2, 2 * n);

  ll numberOf2x2 = size / 4;

  for (int i = 0; i < q; i++) {
    string s;
    cin >> s;
    if (s == "->") {
      int x, y;
      cin >> x >> y;
      cout << f(n, x, y) << endl;
    } else {
      ll N;
      cin >> N;
      pair<int, int> p = d(n, N);
      cout << p.first << " " << p.second << endl;
    }
  }
}

int main() {
  fastIO();

  tc solve();

  return 0;
}