#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> numNodeInSubtree, parentNode;
vector<vector<int>> adj;

int countSubTreeNodes(int node, int parent) {
  parentNode[node] = parent;
  int count = 1;

  for (auto child : adj[node]) {
    if (child == parent)
      continue;
    count += countSubTreeNodes(child, node);
  }

  return numNodeInSubtree[node] = count;
}

void subTree(int u, int v, int count, vector<int> &V) {

  int total1s = count;

  // node, parent
  queue<pair<int, int>> q;

  q.push({u, v});

  while (total1s > 0 && !q.empty()) {

    auto [node, parent] = q.front();
    q.pop();

    V[node] = total1s > 0;
    total1s--;

    for (auto child : adj[node]) {
      if (child != parent)
        q.push({child, node});
    }
  }
}

void solve() {
  int n, k;
  cin >> n >> k;

  adj.assign(n, vector<int>());
  numNodeInSubtree.assign(n, 0);
  parentNode.assign(n, -1);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }

  if (k == n || k == 0) {
    cout << 1 << endl;

    for (int i = 0; i < n; i++) {
      if (k == n)
        cout << 1 << " ";
      else
        cout << 0 << " ";
    }
    cout << endl;
    return;
  }

  countSubTreeNodes(0, -1);

  int diff = INT_MAX;
  int snode = -1;
  for (int i = 0; i < n; i++) {
    if (numNodeInSubtree[i] >= k) {
      int nd = numNodeInSubtree[i] - k;
      if (nd < diff) {
        diff = nd;
        snode = i;
      }
    }
  }

  vector<int> values(n, 0);

  if (numNodeInSubtree[snode] == k) {
    cout << 2 << endl;
  } else if (numNodeInSubtree[snode] > k) {
    cout << 3 << endl;
  }

  subTree(snode, parentNode[snode], k, values);
  for (int v : values)
    cout << v << " ";
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
