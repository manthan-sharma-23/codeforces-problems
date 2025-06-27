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
#define hash_map(T1, T2) unordered_map<T1, T2, custom_hash>
#define hash_set(T) unordered_set<T>
#define loop(i, a, b, step) for (int i = (a); i < (b); i += step)
#define asc(v) sort((v).begin(), (v).end())
#define dsc(v) sort((v).rbegin(), (v).rend())
#define MOD 1000000007

using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vll = vector<ll>;
using vi = vector<int>;

void solve() {
  int n;
  cin >> n;

  vector<vi> opr;

  for (int row = 0; row < n; row++) {

    int ll = n - row;

    if (ll > 1) {
      opr.push_back({row + 1, 1, ll});
    }
    if (n - ll > 1) {
      opr.push_back({row + 1, ll + 1, n});
    }
  }

  cout << opr.size() << endl;
  each(op, opr) { cout << op[0] << " " << op[1] << " " << op[2] << endl; }
}

int main() {
  // usaco();
  FIO tc solve();

  return 0;
}
