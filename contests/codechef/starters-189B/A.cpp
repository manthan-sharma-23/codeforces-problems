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

void solve() {
  int n, c;
  cin >> n >> c;

  vi a(n), b(n);
  each(it, a) cin >> it;
  each(it, b) cin >> it;

  hash_map(int, int) mp;

  // Track minimum b[i] for each unique a[i]
  for (int i = 0; i < n; i++) {
    if (!mp.count(a[i]))
      mp[a[i]] = b[i];
    else
      mp[a[i]] = min(mp[a[i]], b[i]);
  }

  vi d;
  each(it, mp) d.push_back(it.S);
  asc(d);

  int cost = 0, count = 0;
  int maxc = 0;

  // Try to select k values from d to maximize (c * k - total_cost)
  for (int v : d) {
    cost += v;
    count++;
    int ss = c * count - cost;
    maxc = max(maxc, ss); // track max value of (c * count - cost)
  }

  cout << maxc << endl;
}

int main() {
  // usaco();
  FIO tc solve();

  return 0;
}
