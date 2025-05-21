#include <bits/stdc++.h>
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

int ceilLog2(long long x) {
  if (x <= 1)
    return 0;
  return 64 - __builtin_clzll(x - 1);
}

void solve() {
  ll n;
  cin >> n;
  string r;

  cout << "mul 9" << endl;
  cout.flush();
  cin >> r;
  if (r == "-1")
    return;

  cout << "digit" << endl;
  cout.flush();
  cin >> r;
  if (r == "-1")
    return;

  cout << "digit" << endl;
  cout.flush();
  cin >> r;
  if (r == "-1")
    return;

  cout << "add " << (n - 9) << endl;
  cout.flush();
  cin >> r;
  if (r == "-1")
    return;
  cout << "!" << endl;
  cout.flush();
  cin >> r;
  if (r == "-1")
    return;
}

int main() {
  fastIO();
  tc solve();
  return 0;
}