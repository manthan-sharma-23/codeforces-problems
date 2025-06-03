#include <bits/stdc++.h>
#include <numeric>
// manthan's code
using namespace std;
#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
#define FIO                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);
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

void usaco(string name = "h") {

  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}

struct DSU {
  vi teams, parent;
  vll strength, size;

  DSU(int n) {
    strength.resize(n);
    parent.resize(n);
    teams.resize(n);

    size.assign(n, 1LL);

    iota(parent.begin(), parent.end(), 0);
    iota(teams.begin(), teams.end(), 0);
    iota(strength.begin(), strength.end(), 1LL);
  }

  int find(int x) {
    if (parent[x] == x)
      return x;
    else
      return parent[x] = find(parent[x]);
  }

  void unite(int x, int y) {
    int tx = teams[x], ty = teams[y];

    int rtx = find(tx), rty = find(ty);

    if (rtx == rty)
      return;

    if (size[rtx] < size[rty]) {
      swap(rtx, rty);
      swap(x, y);
    }

    parent[y] = rtx;
    strength[rtx] += strength[rty];
    size[rtx] += size[rty];
  }

  void strength_size(int x) {
    cout << size[find(teams[x])] << " " << strength[find(teams[x])] << endl;
  }

  void remove(int x, int y) {
    int tx = teams[x], ty = teams[y];

    int rtx = find(tx), rty = find(ty);

    if (rtx == rty)
      return;

    strength[rtx] -= x + 1;
    size[rtx]--;

    strength[rty] += x + 1;
    size[rty]++;
    teams[x] = rty;
  }
};

void solve() {
  int n, q;
  cin >> n >> q;

  DSU dsu(n);

  while (q--) {
    int T;
    cin >> T;

    if (T == 1) {
      int x, y;
      cin >> x >> y;
      x--, y--;

      dsu.unite(x, y);
    } else if (T == 2) {
      int x;
      cin >> x;
      x--;

      dsu.strength_size(x);

    } else {
      int x, y;
      cin >> x >> y;
      x--, y--;

      dsu.remove(x, y);
    }
  }
}

int main() {
  // usaco();
  FIO tc solve();

  return 0;
}
