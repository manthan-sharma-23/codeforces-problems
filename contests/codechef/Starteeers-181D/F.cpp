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
bool isPossible = true;

pair<int, bool> f(int node, int parent) {
  bool thisNodeColored = false;
  queue<int> notColored, colored;

  for (int &child : adj[node]) {
    if (child == parent)
      continue;

    auto r = f(child, node);
    if (!r.second)
      notColored.push(r.first);
    else
      colored.push(r.first);
  }

  while (!notColored.empty() && !colored.empty()) {
    int nc = notColored.front();
    notColored.pop();
    int cc = colored.front();
    colored.pop();
    colors[nc] = colors[cc];
  }

  if (colored.size() == 1) {
    colors[node] = colors[colored.front()];
    colored.pop();
    thisNodeColored = true;
  } else if (!colored.empty()) {
    isPossible = false;
    return {node, false};
  }

  if (!notColored.empty() && notColored.size() % 2 != 0) {
    colors[node] = colors[notColored.front()] = newColor++;
    thisNodeColored = true;
    notColored.pop();
  }

  while (notColored.size() >= 2) {
    int nc1 = notColored.front();
    notColored.pop();
    int nc2 = notColored.front();
    notColored.pop();
    colors[nc1] = colors[nc2] = newColor++;
  }

  if (!notColored.empty() || !colored.empty()) {
    isPossible = false;
  }

  return {node, thisNodeColored};
}

void solve() {
  int n;
  cin >> n;

  adj.assign(n + 1, vector<int>());
  colors.assign(n + 1, 0);
  newColor = 1;
  isPossible = true;

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

  auto res = f(1, -1);
  if (!res.second || !isPossible) {
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
