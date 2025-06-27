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

ll dp[20][2][2];

ll f(int idx, bool tight, bool has3, const string &s) {
  if (idx == s.length())
    return has3;

  if (dp[idx][tight][has3] != -1)
    return dp[idx][tight][has3];

  int limit = tight ? s[idx] - '0' : 9;

  ll ans = 0;

  for (int d = 0; d <= limit; d++) {
    ans += f(idx + 1, tight & (d == limit), has3 | (d == 3), s);
  }

  return dp[idx][tight][has3] = ans;
}

void solve() {
  ll n;
  cin >> n;

  string s = to_string(n);

  memset(dp, -1LL, sizeof(dp));
  ll c3 = f(0, 1, 0, s);

  cout << n - c3 << endl;
}

int main() {

  // usaco();
  FIO tc solve();

  return 0;
}
