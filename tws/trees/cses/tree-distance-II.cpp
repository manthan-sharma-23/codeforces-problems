#include <bits/stdc++.h>
using namespace std;

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
#define dsc(v) sort((v).rbegin(), (v).end())
#define MOD 1000000007
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define vll vector<ll>
#define vi vector<int>

vector<vi> adj;
vll largest, secondLargest, res;
vi largestFrom, secondLargestFrom;

ll dfs1(int u, int parent) {
  ll &l = largest[u], &sl = secondLargest[u];

  each(child, adj[u]) {
    if (parent == child)
      continue;

    ll d = dfs1(child, u);

    if (d > l) {
      sl = l;
      secondLargestFrom[u] = largestFrom[u];

      l = d;
      largestFrom[u] = child;
    } else if (d > sl) {
      sl = d;
      secondLargestFrom[u] = child;
    }
  }

  return l + 1;
}

void dfs2(int u, int parent) {
  ll maxV = largest[u];

  if (parent != 0) {
    if (largestFrom[parent] != u && largest[parent] + 1 > maxV) {
      maxV = largest[parent] + 1;
      largest[u] = maxV;
      largestFrom[u] = parent;
    } else if (secondLargest[parent] + 1 > maxV) {
      maxV = secondLargest[parent] + 1;
      secondLargest[u] = maxV;
      secondLargestFrom[u] = parent;
    }
  }

  res[u] = maxV;

  cout << u << " " << maxV << " " << largestFrom[u] << " " << parent << " "
       << largest[parent] << endl;

  each(child, adj[u]) {
    if (child == parent)
      continue;
    dfs2(child, u);
  }
}

void solve() {
  int n;
  cin >> n;

  adj.assign(n + 1, {});
  largest.assign(n + 1, 0);
  secondLargest.assign(n + 1, 0);
  largestFrom.assign(n + 1, 0);
  secondLargestFrom.assign(n + 1, 0);
  res.assign(n + 1, 0);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs1(1, 0);
  dfs2(1, 0);
  cout << endl << endl;
  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
}

int main() {
  FIO solve();
  return 0;
}
