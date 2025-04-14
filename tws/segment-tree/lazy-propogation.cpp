#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
  const int n;
  vector<int> node;
  vector<int> lazyNode;

  void updateLazy(int index, int l, int r) {
    if (lazyNode[index] != 0) {
      int lazyVal = lazyNode[index];
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

  int rangeSum(int index, int s, int e, int l, int r) {
    updateLazy(index, s, e);

    if (r < s || l > e)
      return 0;

    if (s >= l && e <= r)
      return node[index];

    int mid = (s + e) / 2;
    int left = rangeSum(2 * index + 1, s, mid, l, r);
    int right = rangeSum(2 * index + 2, mid + 1, e, l, r);
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

  int sum(int l, int r) { return rangeSum(0, 0, n - 1, l, r); }
};

int main() {
  vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7};
  SegmentTree sgt(arr);

  cout << sgt.sum(0, 7) << endl;

  sgt.rangeUpdate(2, 4, 1);

  cout << sgt.sum(0, 7) << endl;

  sgt.update(3, 100);

  cout << sgt.sum(0, 7) << endl;
}
