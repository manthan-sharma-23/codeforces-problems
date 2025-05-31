#include <bits/stdc++.h>
using namespace std;

#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
#define asc(v) sort((v).begin(), (v).end())
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n, k;
  cin >> n >> k;
  vi a(n), b(n);
  each(it, a) cin >> it;
  each(it, b) cin >> it;

  vector<vi> thieves(n, vi(3));
  for (int i = 0; i < n; i++) {
    thieves[i][0] = a[i];
    thieves[i][1] = b[i];
    thieves[i][2] = i;
  }

  asc(thieves);

  vll res(n, 0);
  min_heap(ll) pq;
  ll sum = 0;

  for (int i = 0; i < n; i++) {
    int idx = thieves[i][2];
    ll gold = thieves[i][1];
    res[idx] = sum;

    if ((int)pq.size() < k) {
      pq.push(gold);
      sum += gold;
    } else if (gold > pq.top()) {
      sum -= pq.top();
      pq.pop();
      pq.push(gold);
      sum += gold;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << res[i];
    if (i < n - 1)
      cout << ' ';
    else
      cout << '\n';
  }
}

int main() {
  fastIO();
  tc solve();
  return 0;
}