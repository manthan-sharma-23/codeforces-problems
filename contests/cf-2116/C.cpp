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
#define loop(i, a, b, step) for (int i = (a); i < (b); i += step)
#define asc(v) sort((v).begin(), (v).end())
#define dsc(v) sort((v).rbegin(), (v).rend())
#define MOD 1000000007

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

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void usaco(string name = "h") {

  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}

int gcd_(int a, int b) { return b == 0 ? a : gcd_(b, a % b); }

void solve() {
  int n;
  cin >> n;
  vi a(n);
  each(it, a) cin >> it;

  int G = a[0];
  for (int i = 1; i < n; i++) {
    G = gcd_(G, a[i]);
  }

  int countG = count(a.begin(), a.end(), G);
  if (countG > 0) {
    cout << n - countG << endl;
    return;
  }

  int stp = INT_MAX;
  for (int i = 0; i < n; i++) {
    int g = 0;
    for (int j = i; j < n; j++) {
      g = gcd_(g, a[j]);
      if (g == G) {
        stp = min(stp, j - i + 1);
        break;
      }
    }
  }

  cout << (stp - 1) + (n - 1) << endl;
}

int main() {
  // usaco();
  fastIO();
  tc solve();

  return 0;
}