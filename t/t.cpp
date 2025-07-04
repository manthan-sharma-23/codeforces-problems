#include <bits/stdc++.h>
#include <cstring>
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
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define vll vector<ll>
#define vi vector<int>

vector<bool> cycle;

vi to, visited;

void dfs(int node, vi &path) {
  path.push_back(node);
  visited[node] = 2;

  int next = to[node];

  if (visited[next] == 0) {
    dfs(next, path);
  } else if (visited[next] == 2) {
    while (path.back() != next) {
      cycle[path.back()] = 1;
      path.pop_back();
    }
    cycle[next] = 1;
  }

  visited[node] = 1;
  path.pop_back();
}

void solve() {
  int n;
  cin >> n;

  to.clear(), cycle.clear(), visited.clear();

  to.resize(n, -1);
  cycle.resize(n, 0);
  visited.resize(n, 0);

  vi a(n);
  each(it, a) cin >> it;

  for (int i = 0; i < n; i++) {
    to[i] = (i + 1 + a[i]) % n;
  }

  for (int i = 0; i < n; i++) {
    if (visited[i] == 0) {
      vi p = vi();
      dfs(i, p);
    }
  }

  int magic = 0;

  for (int i = 0; i < n; i++) {
    if (cycle[i])
      magic++;
  }

  cout << magic << endl;
}

int main() {
  // usaco();
  FIO tc solve();

  return 0;
}
