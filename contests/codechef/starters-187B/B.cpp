#include <bits/stdc++.h>
// manthan's code
using namespace std;
#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2, custom_hash>
#define hash_set(T) unordered_set<T>
#define loop(i, a, b, step) for (int i = (a); i < (b); i += step)
#define asc(v) sort((v).begin(), (v).end())
#define dsc(v) sort((v).rbegin(), (v).rend())

using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vll = vector<ll>;
using vi = vector<int>;

const int MOD = 1e9 + 7;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void usaco(string name = "h") {

  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}

vector<int> findYs_fast(int a, int x, int n) {
  if ((a & ~x) != 0)
    return {};

  int m = x & ~a;
  int A = a;

  vector<int> res;
  res.reserve(1 << __builtin_popcount(A));

  for (int s = A;; s = (s - 1) & A) {
    int y = m | s;
    if (y >= 1 && y <= n) {
      res.push_back(y);
    }
    if (s == 0)
      break;
  }

  sort(res.begin(), res.end());
  return res;
}

vector<int> allPossibleYs(int a, int n) {
  vector<int> res;
  for (int sub = a; sub > 0; sub = (sub - 1) & a) {
    if (sub <= n)
      res.push_back(sub);
  }
  return res;
}

void solve() {
  int n, x;
  cin >> n >> x;

  vector<pair<int, vi>> a;
  vi b;

  using pii_vi = pair<int, vi>;

  for (int i = 1; i <= n; i++) {
    vi ys = findYs_fast(i, x, n);

    if (ys.empty())
      b.push_back(i);
    else
      a.emplace_back(i, ys);
  }

  priority_queue<pii_vi, vector<pii_vi>, function<bool(pii_vi &, pii_vi &)>> pq(
      [](pii_vi &a, pii_vi &b) { return a.second.size() > b.second.size(); });

  for (auto &p : a) {

    pq.push(p);
  }

  set<int> idc;

  for (int i = 1; i <= n; i++) {
    idc.insert(i);
  }

  vi res(n + 1);

  while (!pq.empty()) {

    auto top = pq.top();
    pq.pop();

    auto vys = top.second;

    bool inserted = 0;

    each(id, vys) {
      if (!inserted && idc.find(id) != idc.end()) {
        res[id] = top.first;
        idc.erase(id);
        inserted = 1;
        break;
      }
    }

    if (!inserted)
      b.push_back(top.first);
  }

  each(vl, b) {
    int id = *idc.rbegin();
    idc.erase(id);
    res[id] = vl;
  }

  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
  cout << endl;
}

int main() {
  // usaco();
  fastIO();
  tc solve();

  return 0;
}
