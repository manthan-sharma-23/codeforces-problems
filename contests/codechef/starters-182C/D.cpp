#include <bits/stdc++.h>
// manthan's code

#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2>
#define hash_set(T) unordered_set<T>

using namespace std;

typedef unsigned long long ll;

const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

int n;
vector<vector<int>> grid;
ll initialScore;

bool valid(ll k) {
  ll f1 = 0LL;
  ll score = 0;
  for (int i = 0; i < n; i++) {
    f1 += min<ll>(k, grid[0][i]);
  }

  for (int i = 1; i < n; i++) {
    ll fi = 0LL;
    for (int j = 0; j < n; j++) {
      fi += min<ll>(k, grid[i][j]);
    }

    if (fi > f1)
      score++;
  }

  return score == initialScore;
}

ll computeInitialScore() {
  ll f1 = 0LL;
  ll score = 0;
  for (int i = 0; i < n; i++) {
    f1 += grid[0][i];
  }

  for (int i = 1; i < n; i++) {
    ll fi = 0LL;
    for (int j = 0; j < n; j++) {
      fi += grid[i][j];
    }

    if (fi > f1)
      score++;
  }

  return score;
}

int maxTree() {
  int maxVal = grid[0][0];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      maxVal = max(maxVal, grid[i][j]);
    }
  }

  return maxVal;
}

void solve() {

  cin >> n;

  initialScore = 0LL;
  grid.clear();
  grid.resize(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  if (n == 1) {
    cout << 1 << endl;
    return;
  }

  initialScore = computeInitialScore();

  int maxTreeH = maxTree();

  ll low = 1, high = maxTreeH, res = maxTreeH;

  while (low <= high) {
    ll mid = low + (high - low) / 2;

    if (valid(mid)) {
      res = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << res << endl;
}

int main() {
  fastIO();

  tc solve();

  return 0;
}
