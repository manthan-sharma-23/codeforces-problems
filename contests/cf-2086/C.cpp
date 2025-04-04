#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  vector<int> q(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> q[i];
  }

  ll k = 1;
  vector<int> grp(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    if (grp[i] != -1)
      continue;

    grp[i] = k;
    int j = a[i];
    while (j != i) {
      grp[j] = k;
      j = a[j];
    }
    k++;
  }

  vector<int> sz(k + 1, 0);
  vector<bool> vis(k + 1, false);

  for (int i = 1; i <= n; i++) {
    sz[grp[i]]++;
  }

  vector<int> res;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    int query = q[i];
    int group = grp[query];

    if (!vis[group]) {
      vis[group] = true;
      ans += sz[group];
    }

    res.push_back(ans);
  }

  for (int r : res) {
    cout << r << " ";
  }
  cout << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}