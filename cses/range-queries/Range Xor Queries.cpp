#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
  vector<int> arr;
  vector<int> tree;
  const int n;

  void build(int index, int s, int e) {
    if (s == e) {
      tree[index] = arr[s];
      return;
    }
    int mid = s + (e - s) / 2;
    build(2 * index + 1, s, mid);
    build(2 * index + 2, mid + 1, e);
    tree[index] = tree[2 * index + 1] ^ tree[2 * index + 2];
  }

  int rangeXor(int index, int s, int e, int l, int r) {
    if (e < l || s > r)
      return 0; // XOR identity
    if (s >= l && e <= r)
      return tree[index];
    int mid = s + (e - s) / 2;
    int left = rangeXor(2 * index + 1, s, mid, l, r);
    int right = rangeXor(2 * index + 2, mid + 1, e, l, r);
    return left ^ right;
  }

  void update(int index, int s, int e, int pos, int val) {
    if (s == e) {
      arr[pos] = val;
      tree[index] = val;
      return;
    }
    int mid = s + (e - s) / 2;
    if (pos <= mid) {
      update(2 * index + 1, s, mid, pos, val);
    } else {
      update(2 * index + 2, mid + 1, e, pos, val);
    }
    tree[index] = tree[2 * index + 1] ^ tree[2 * index + 2];
  }

public:
  SegmentTree(vector<int> &arr) : n(arr.size()) {
    this->arr = arr;
    tree.assign(4 * n, 0);
    build(0, 0, n - 1);
  }

  int rxq(int l, int r) { return rangeXor(0, 0, n - 1, l, r); }

  void pointUpdate(int pos, int val) {
    if (pos < 0 || pos >= n)
      return;
    update(0, 0, n - 1, pos, val);
  }
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
    int l, r;

    cin >> l >> r;

    l--, r--;

    cout << segTree.rxq(l, r) << endl;
  }

  return 0;
}
