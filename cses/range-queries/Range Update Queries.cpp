#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class SegmentTree {
private:
  const int n;
  vector<ll> node;
  vector<ll> lazyNode;

  void updateLazy(int index, int l, int r) {
    if (lazyNode[index] != 0) {
      ll lazyVal = lazyNode[index];
      node[index] += (r - l + 1) * lazyVal;

      if (l != r) {
        lazyNode[2 * index + 1] += lazyVal;
        lazyNode[2 * index + 2] += lazyVal;
      }

      lazyNode[index] = 0;
    }
  }

  void build(int index, int l, int r, const vector<int> &nums) {
    if (l == r) {
      node[index] = nums[l];
    } else {
      int mid = (l + r) / 2;
      build(2 * index + 1, l, mid, nums);
      build(2 * index + 2, mid + 1, r, nums);
      node[index] = node[2 * index + 1] + node[2 * index + 2];
    }
  }

  void rangeUpdate(int index, int s, int e, int l, int r, int val) {
    updateLazy(index, s, e);

    if (r < s || l > e)
      return;

    if (s >= l && e <= r) {
      node[index] += (e - s + 1) * val;
      if (s != e) {
        lazyNode[2 * index + 1] += val;
        lazyNode[2 * index + 2] += val;
      }
      return;
    }

    int mid = (s + e) / 2;
    rangeUpdate(2 * index + 1, s, mid, l, r, val);
    rangeUpdate(2 * index + 2, mid + 1, e, l, r, val);
    node[index] = node[2 * index + 1] + node[2 * index + 2];
  }

  ll rangeSum(int index, int s, int e, int l, int r) {
    updateLazy(index, s, e);

    if (r < s || l > e)
      return 0;

    if (s >= l && e <= r)
      return node[index];

    int mid = (s + e) / 2;
    ll left = rangeSum(2 * index + 1, s, mid, l, r);
    ll right = rangeSum(2 * index + 2, mid + 1, e, l, r);
    return left + right;
  }

  void update(int index, int s, int e, int pos, int val) {
    updateLazy(index, s, e);

    if (s == e) {
      node[index] = val;
      return;
    }

    int mid = (s + e) / 2;
    if (pos <= mid)
      update(2 * index + 1, s, mid, pos, val);
    else
      update(2 * index + 2, mid + 1, e, pos, val);

    node[index] = node[2 * index + 1] + node[2 * index + 2];
  }

public:
  SegmentTree(vector<int> arr) : n(arr.size()) {
    node.resize(4 * n, 0);
    lazyNode.resize(4 * n, 0);
    build(0, 0, n - 1, arr);
  }

  void rangeUpdate(int l, int r, int val) {
    rangeUpdate(0, 0, n - 1, l, r, val);
  }

  void update(int pos, int val) { update(0, 0, n - 1, pos, val); }

  ll sum(int l, int r) { return rangeSum(0, 0, n - 1, l, r); }
};

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  SegmentTree segTree(arr);

  while (q--) {
    int t;
    cin >> t;

    if (t == 1) {
      int a, b, u;
      cin >> a >> b >> u;
      a--, b--;
      segTree.rangeUpdate(a, b, u);
    } else {
      int k;

      cin >> k;
      k--;
      cout << segTree.sum(k, k) << endl;
    }
  }

  return 0;
}
