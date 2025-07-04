#include <bits/stdc++.h>
using namespace std;

// Manthan's code style
#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define FIO                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);
#define each(x, v) for (auto &x : v)
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define ii pair<int, int>

const ll INF = 1e18;

vvi adj;
vvll dist;
int n, m;

void bfs(int s) {
  queue<int> q;
  vector<bool> visited(n, false);
  dist[s][s] = 0;
  visited[s] = true;
  q.push(s);

  while (!q.empty()) {
    int top = q.front();
    q.pop();
    for (int child : adj[top]) {
      if (!visited[child]) {
        dist[s][child] = dist[s][top] + 1;
        dist[child][s] = dist[s][child];
        visited[child] = true;
        q.push(child);
      }
    }
  }
}

void solve() {
  cin >> n >> m;
  int edges = m;
  adj.assign(n, vi());
  dist.assign(n, vll(n, INF));

  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int s1, t1, l1;
  cin >> s1 >> t1 >> l1;
  s1--, t1--;

  int s2, t2, l2;
  cin >> s2 >> t2 >> l2;
  s2--, t2--;

  for (int i = 0; i < n; i++)
    bfs(i);

  ll minEdges = INF;

  if (dist[s1][t1] <= l1 && dist[s2][t2] <= l2) {
    minEdges = dist[s1][t1] + dist[s2][t2];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll d = dist[i][j];
      ll path1 = d + min(dist[s1][i] + dist[j][t1], dist[s1][j] + dist[i][t1]);
      ll path2 = d + min(dist[s2][i] + dist[j][t2], dist[s2][j] + dist[i][t2]);

      if (path1 <= l1 && path2 <= l2) {
        minEdges = min(minEdges, path1 + path2 - d);
      }
    }
  }

  if (minEdges > edges)
    cout << -1 << '\n';
  else
    cout << edges - minEdges << '\n';
}

int main() {
  FIO solve();
  return 0;
}
