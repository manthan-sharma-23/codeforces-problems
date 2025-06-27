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

int n, m, k;
vector<vi> adj;
vector<bool> danger;

int pathCount;

void dfs(int u, int parent, int maxPref, int currSum) {
  bool isLeaf = adj[u].size() == 1;

  int newDanger = currSum + danger[u];
  int maxDanger = max(maxPref, currSum);

  if (isLeaf && maxDanger <= m) {
    pathCount++;
  }

  each(child, adj[u]) {
    if (child == parent)
      continue;
    int passDanger = danger[u] == 0 ? 0 : newDanger;
    dfs(child, u, maxDanger, passDanger);
  }
}

void solve() {

  cin >> n >> m >> k;
  pathCount = 0;

  adj.resize(n, {});

  danger.resize(n, 0);

  vector<vi> edges(n, vi(2, -1));

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    danger[i] = temp;
  }

  each(it, edges) { cin >> it[0] >> it[1]; }

  each(it, edges) {
    int u = it[0], v = it[1];
    adj[u].resize(v);
    adj[v].resize(u);
  }

  dfs(0, -1, 0, 0);
}

int main() {
  // usaco();
  FIO tc solve();

  return 0;
}
