#include <bits/stdc++.h>
// manthan's code
using namespace std;
#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define FIO                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);
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

struct DSU {
  vi parent, size;
  int components;

  DSU(int n) {
    components = n;
    parent.resize(n, -1);
    size.resize(n, 1);
  }

  int find(int x) {
    if (parent[x] == -1)
      return x;
    else
      return parent[x] = find(parent[x]);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);

    if (x == y)
      return 0;

    if (size[x] < size[y])
      swap(x, y);

    parent[y] = x;
    size[x] += size[y];

    components--;

    return 1;
  }
};

void solve() {
  int n, q, s, m;

  cin >> n;
  cin >> m;

  cin >> s;

  DSU dsu(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    dsu.unite(a, b);
  }

  cin >> q;
  cin >> s;

  while (q--) {
    int a, b;
    cin >> a >> b;

    a--, b--;

    dsu.unite(a, b);
    cout << dsu.components - 1 << " ";
  }

  cout << endl;
}

int main() {
  // usaco();
  FIO solve();

  return 0;
}
