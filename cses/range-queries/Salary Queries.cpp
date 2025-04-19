#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class SegmentTree {
private:
  vector<int> &a;
  const int eachBucketSize = 100;
  unordered_map<int, vector<ll>> trees;

  void ensureTree(int tree) {
    if (!trees.count(tree)) {
      trees[tree] = vector<ll>(4 * eachBucketSize, 0);
    }
  }

  void update(const int tree, int index, int s, int e, int pos, int val) {
    ensureTree(tree);
    if (s == e) {
      trees[tree][index] += val;
      return;
    }

    int mid = s + (e - s) / 2;
    if (pos <= mid) {
      update(tree, 2 * index, s, mid, pos, val);
    } else {
      update(tree, 2 * index + 1, mid + 1, e, pos, val);
    }

    trees[tree][index] = trees[tree][2 * index] + trees[tree][2 * index + 1];
  }

  ll range(const int tree, int index, int s, int e, int l, int r) {
    if (!trees.count(tree))
      return 0;
    if (e < l || s > r)
      return 0;
    if (s >= l && e <= r)
      return trees[tree][index];

    int mid = s + (e - s) / 2;
    ll left = range(tree, 2 * index, s, mid, l, r);
    ll right = range(tree, 2 * index + 1, mid + 1, e, l, r);
    return left + right;
  }

public:
  SegmentTree(vector<int> &a) : a(a) {
    for (int salary : a) {
      int tree = salary / eachBucketSize;
      int pos = salary % eachBucketSize;
      update(tree, 1, 0, eachBucketSize - 1, pos, 1);
    }
  }

  void update(int k, int newSalary) {
    int oldSalary = a[k];

    update(oldSalary / eachBucketSize, 1, 0, eachBucketSize - 1,
           oldSalary % eachBucketSize, -1);
    update(newSalary / eachBucketSize, 1, 0, eachBucketSize - 1,
           newSalary % eachBucketSize, 1);

    a[k] = newSalary;
  }

  ll query(int l, int r) {
    int leftBucket = l / eachBucketSize;
    int rightBucket = r / eachBucketSize;

    ll total = 0;

    for (int bucket = leftBucket; bucket <= rightBucket; ++bucket) {
      int start = 0, end = eachBucketSize - 1;

      if (bucket == leftBucket)
        start = l % eachBucketSize;
      if (bucket == rightBucket)
        end = r % eachBucketSize;

      total += range(bucket, 1, 0, eachBucketSize - 1, start, end);
    }

    return total;
  }
};

void solve() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int &it : a)
    cin >> it;

  SegmentTree st(a);

  while (q--) {
    char ch;
    cin >> ch;

    if (ch == '!') {
      int k, x;
      cin >> k >> x;
      st.update(k - 1, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.query(l, r) << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
