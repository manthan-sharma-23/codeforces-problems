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
#define hash_map(T1, T2) unordered_map<T1, T2>
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

vector<vi> adj;
vi a;

void solve() {
  int n, m;
  cin >> n >> m;

  a.resize(n);
  adj.assign(n, {});

  for (int i = 0; i < n; i++)
    cin >> a[i];

  vi indegree(n, 0);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    indegree[v]++;
  }

  vi minNode(n, 0);

  for (int i = 0; i < n; i++)
    minNode[i] = a[i];

  queue<int> q;
  for (int i = 0; i < n; i++)
    if (indegree[i] == 0)
      q.push(i);

  int maxi = 0;

  while (!q.empty()) {

    int u = q.front();
    q.pop();

    each(v, adj[u]) {
      minNode[v] = min(minNode[v], minNode[u]);

      if (--indegree[v] == 0) {
        maxi = max(maxi, a[v] - minNode[v]);
        q.push(v);
      }
    }
  }

  cout << maxi << endl;
}

int main() {
  // usaco();
  FIO tc solve();

  return 0;
}
