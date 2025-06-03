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
#define F first
#define S second

using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vll = vector<ll>;
using vi = vector<int>;

struct DSU {
  int parent[26], size[26];

  DSU() {
    memset(parent, -1, sizeof(parent));
    memset(size, 0, sizeof(size));
  }

  int find(int c) {
    if (parent[c] == -1)
      return c;
    else
      return parent[c] = find(parent[c]);
  }

  void unite(int a, int b) {
    a = find(a), b = find(b);

    if (a == b)
      return;

    if (size[a] < size[b])
      swap(a, b);

    parent[b] = a;
    size[a] += size[b];
  }
};

void solve() {
  int n;
  cin >> n;

  DSU dsu;

  string s;
  cin >> s;

  int prev = 0;
  map<ii, int> mp;

  for (int i = 0; i < n / 2; i++) {
    int v1 = s[i] - 'a', v2 = s[n - i - 1] - 'a';

    if (v1 != v2) {
      if (v1 > v2)
        swap(v1, v2);
      prev++;
      mp[{v1, v2}]++;
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int T;
    cin >> T;

    if (T == 1) {
      char a, b;
      cin >> a >> b;

      int v1 = a - 'a', v2 = b - 'a';

      if (v1 > v2)
        swap(v1, v2);

      if (dsu.find(v1) == dsu.find(v2))
        continue;
      else
        dsu.unite(v1, v2);

      map<ii, int> mp1;
      each(it, mp) {
        int vv1 = it.F.F;
        int vv2 = it.F.S;

        int r1 = dsu.find(vv1);
        int r2 = dsu.find(vv2);
        if (r1 == r2) {
          prev -= it.S;
        } else {
          if (r1 > r2)
            swap(r1, r2);
          mp1[{r1, r2}] += it.S;
        }
      }
      mp = mp1;

    } else {
      cout << prev << endl;
    }
  }
}

int main() {
  // usaco();
  FIO solve();

  return 0;
}
