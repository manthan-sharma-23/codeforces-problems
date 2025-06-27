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

int n;
ll dp[1000001][2][2];

ll f(int idx, int last, int taken) {
  if (idx == n) {
    if (taken == 1)
      return 1LL;
    else
      return 0LL;
  }

  if (idx != 0 && dp[idx][last][taken] != -1) {
    return dp[idx][last][taken];
  }

  int ways = 0LL;

  ways += f(idx + 1, 1, taken);

  if (last == 0) {
    if (taken == 0)
      ways += f(idx + 1, 0, 1); // new "00" formed
  } else {
    ways += f(idx + 1, 0, taken);
  }

  if (idx == 0) {
    return ways;
  }

  return dp[idx][last][taken] = ways;
}

void solve() {
  cin >> n;

  memset(dp, -1, sizeof(dp));

  cout << f(0, -1, 0) << endl;
}

int main() {
  // usaco();
  FIO tc solve();

  return 0;
}
