#include <bits/stdc++.h>
using namespace std;

/*
  We are given:
    - n
    - array a[0..n-1]
    - a permutation d[0..n-1] (1-based in input: “positions to destroy in
  order”)

  We want to output, after each removal, the maximum sum of a contiguous segment
  of the remaining array. The standard trick is to process “in reverse”: start
  with an empty array, then “turn on” elements in the reverse order of
  destruction, keep a DSU of active segments, track the running maximum segment
  sum, and record it just before each activation.

  This version does:
   1) Read n, a[], d[].
   2) Convert d[i] to 0-based immediately and assert it’s in [0..n-1].
   3) Maintain a DSU that holds sum‐of‐component in `compSum[root]`.
   4) Maintain a bool alive[i] = whether position i is “turned on”.
   5) Build backwards:
         — Initially no one is “alive,” so current_max = 0.
         — For i = n−1 down to 0:
             • record ansBefore[i] = current_max
               (this corresponds to “what the max‐segment sum was just before
  re‐adding d[i]”) • let x = d[i]; now mark alive[x] = true • if (x−1 ≥ 0 &&
  alive[x−1])   unite(x, x−1) • if (x+1 <  n && alive[x+1])   unite(x, x+1) •
  current_max = max(current_max, DSU::getSum(x)) 6) Finally, print
  ansBefore[0..n−1] in order—one per line.

  Note: On Codeforces, they expect exactly n lines of output: the max‐sum after
  each removal. Here, ansBefore[k] is “the max‐sum just before we turn on d[k],”
  which equals “after k removals” when you run forwards.  (That lines up
  perfectly with the usual problem statement.)

  We also replace any recursive `find()` by an iterative version to avoid
  stack-overflow in pathological cases. We add an assert to ensure no invalid
  d[i] ever sneaks in.
*/

struct DSU {
  int n;
  vector<int> parent, sz;
  vector<long long> compSum;

  DSU(int _n, const vector<long long> &vals) : n(_n) {
    parent.resize(n);
    sz.resize(n, 1);
    compSum.resize(n, 0);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      compSum[i] = vals[i];
    }
  }

  int findRoot(int x) {
    int r = x;
    while (r != parent[r]) {
      r = parent[r];
    }
    int cur = x;
    while (cur != r) {
      int nxt = parent[cur];
      parent[cur] = r;
      cur = nxt;
    }
    return r;
  }

  void unite(int x, int y) {
    x = findRoot(x);
    y = findRoot(y);
    if (x == y)
      return;
    if (sz[x] < sz[y])
      swap(x, y);
    parent[y] = x;
    sz[x] += sz[y];
    compSum[x] += compSum[y];
  }

  long long getSum(int x) {
    int r = findRoot(x);
    return compSum[r];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    d[i]--; // Convert to 0-based
    assert(d[i] >= 0 && d[i] < n);
  }

  DSU dsu(n, a);

  vector<bool> alive(n, false);
  vector<long long> ansBefore(n, 0LL);

  long long current_max = 0LL;

  for (int i = n - 1; i >= 0; i--) {
    ansBefore[i] = current_max;

    int x = d[i];
    alive[x] = true;
    if (x - 1 >= 0 && alive[x - 1]) {
      dsu.unite(x, x - 1);
    }
    if (x + 1 < n && alive[x + 1]) {
      dsu.unite(x, x + 1);
    }
    long long segSum = dsu.getSum(x);
    if (segSum > current_max) {
      current_max = segSum;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ansBefore[i] << "\n";
  }

  return 0;
}
