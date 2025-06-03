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
  vector<int> parent, size;

  DSU(int n) {
    parent.resize(n);

    iota(parent.begin(), parent.end(), 0);
    size.assign(n, 1);
  }

  int find(int x) {
    if (parent[x] == x)
      return x;
    else
      return parent[x] = find(parent[x]);
  }

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
      return 0;

    if (size[x] < size[y])
      swap(x, y);

    size[x] += size[y];
    parent[y] = x;

    return 1;
  }

  int size_(int x) { return size[find(x)]; }
};

void solve() {
  int n, q;

  cin >> n >> q;

  DSU dsu(n);

  while (q--) {
    char j;
    cin >> j;
    if (j == 'M') {
      int a, b;
      cin >> a >> b;
      a--, b--;

      dsu.unite(a, b);
    } else {
      int a;
      cin >> a;
      a--;

      cout << dsu.size_(a) << endl;
    }
  }
}

int main() { FIO solve(); }