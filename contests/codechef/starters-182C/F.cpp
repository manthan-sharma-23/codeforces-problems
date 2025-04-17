#include <bits/stdc++.h>

#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2>
#define hash_set(T) unordered_set<T>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

vector<vector<int>> leaves;
vector<bool> isLeaf;
vector<vector<int>> adj;

vector<int> colors;
vector<int> values;

void dfs1(int u, int parent) {
  bool hasChild = false;

  each(v, adj[u]) {
    if (v == parent)
      continue;
    hasChild = true;
    dfs1(v, u);
    leaves[u].insert(leaves[u].end(), leaves[v].begin(), leaves[v].end());
  }

  if (!hasChild) {
    isLeaf[u] = true;
    leaves[u].push_back(u);
  }
}

vector<ll> res;

hash_map(int, int) dfs2(int node, int parent) {
  ll ci = 0, vi = 0;
  hash_map(int, int) mp;

  mp[colors[node]] = values[node];
  if (isLeaf[node]) {
    res[node] = values[node];
    return mp;
  }

  ll tSum = values[node];

  each(child, adj[node]) { 
    if (child == parent)
      continue;

    auto temp = dfs2(child, node);
    each(it, temp) {
      mp[it.first] += it.second;
      tSum += it.second;
    }
  }

  ll maxScore = 0;

  each(leaf, leaves[node]) {
    ll tempSum = tSum;
    tempSum -= mp[colors[leaf]];

    ll newSum = mp[colors[leaf]];
    if ((newSum - values[leaf]) != 0) {
      tempSum += abs(newSum - 2 * values[leaf]);
    } else {
      tempSum += values[leaf];
    }

    maxScore = max(tempSum, maxScore);
  }

  res[node] = maxScore;

  return mp;
}

void solve() {
  int n;
  cin >> n;

  adj.assign(n + 1, {});
  isLeaf.assign(n + 1, false);
  leaves.assign(n + 1, {});
  res.assign(n + 1, 0LL);
  colors.assign(n + 1, 0);
  values.assign(n + 1, 0);

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    cin >> colors[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> values[i];
  }

  dfs1(1, -1);

  dfs2(1, -1);

  for (int i = 1; i <= n; i++) {
    cout << res[i] << "\n";
  }
}

int main() {
  fastIO();
  tc solve();
  return 0;
}