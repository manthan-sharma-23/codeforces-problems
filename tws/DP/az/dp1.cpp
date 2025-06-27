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

ll dp[2010][10][510];
int n, d;

ll f(int idx, int prev, int rem) {
  if (idx == n) {
    return 1;
  }

  ll &res = dp[idx][prev][rem];

  if (res != -1)
    return res;

  res = 0LL;

  for (int i = 1; i <= 9; i += 2) {
    if (prev != i)
      res += f(idx + 1, i, (rem * 10 + i));
  }
}

int solve() { cin >> n >> d; }

int main() {
  // usaco();
  FIO solve();

  return 0;
}
