#include <bits/stdc++.h>
using namespace std;

#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2>
#define hash_set(T) unordered_set<T>

typedef long long ll;
const int MOD = 1e9 + 7;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

vector<vector<int>> adj;
vector<int> colors;
int newColor;

bool dfs(int node, int parent) {
  vector<int> children;

  each(child, adj[node]) {
    if (child == parent)
      continue;

    children.push_back(child);
    if (!dfs(child, node))
      return false;
  }

  if (parent == -1) {
    if (children.size() % 2 == 0)
      return false;

    colors[node] = colors[*children.rbegin()] = ++newColor;
    children.pop_back();
  } else {
    if (children.size() % 2 != 0)
      return false;
  }

  for (int i = 0; i < children.size(); i += 2) {
    colors[children[i]] = colors[children[i + 1]] = ++newColor;
  }

  return true;
}

void solve() {
  int n;
  cin >> n;

  adj.assign(n + 1, vector<int>());
  colors.assign(n + 1, 0);
  newColor = 0;

  if (n == 1) {
    cout << 1 << endl;
    return;
  }

  for (int i = 2; i <= n; i++) {
    int u;
    cin >> u;
    adj[i].push_back(u);
    adj[u].push_back(i);
  }

  bool res = dfs(1, -1);
  if (!res) {
    cout << -1 << endl;
  } else {
    for (int i = 1; i <= n; i++) {
      cout << colors[i] << " ";
    }
    cout << endl;
  }
}

int main() {
  fastIO();
  tc solve();
  return 0;
}
