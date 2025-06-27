#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll k;
vector<ll> arr;
vector<array<ll, 65>> cost, gain;
ll dfs(int i, ll usedCost, vector<unordered_map<ll, ll>> &memo) {
  if (usedCost > k)
    return (ll)-1e18;
  if (i == n)
    return 0;
  auto &M = memo[i];
  if (auto it = M.find(usedCost); it != M.end())
    return it->second;

  ll best = -1e18;
  for (int op = 0; op <= 64; ++op) {
    ll c = cost[i][op];
    if (usedCost + c > k)
      break;
    best = max(best, gain[i][op] + dfs(i + 1, usedCost + c, memo));
  }
  return M[usedCost] = best;
}

void solve() {
  cin >> n >> k;
  arr.resize(n);
  for (ll &x : arr)
    cin >> x;

  cost.assign(n, {});
  gain.assign(n, {});

  for (int j = 0; j < n; ++j) {
    unsigned long long uj = (unsigned long long)arr[j];
    for (int op = 0; op <= 64; ++op) {
      unsigned long long mask = (op == 64 ? ~0ULL : (1ULL << op) - 1);
      unsigned long long nv = uj | mask;
      ll c = (ll)(nv - uj);
      if (c > k)
        break;
      cost[j][op] = c;
      gain[j][op] = __builtin_popcountll(nv);
    }
  }

  vector<unordered_map<ll, ll>> memo(n);

  cout << dfs(0, 0, memo) << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
