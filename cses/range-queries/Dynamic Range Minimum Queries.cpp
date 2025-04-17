#include <bits/stdc++.h>

using namespace std;

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
    tree[index] = min(tree[2 * index + 1], tree[2 * index + 2]);
  }

  int rangeMinQuery(int index, int s, int e, int l, int r) {
    if (e < l || s > r)
      return INT_MAX; // out of range
    if (s >= l && e <= r)
      return tree[index]; // completely in range
    int mid = s + (e - s) / 2;
    int left = rangeMinQuery(2 * index + 1, s, mid, l, r);
    int right = rangeMinQuery(2 * index + 2, mid + 1, e, l, r);
    return min(left, right);
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
    tree[index] = min(tree[2 * index + 1], tree[2 * index + 2]);
  }

public:
  SegmentTree(vector<int> &arr) : n(arr.size()) {
    this->arr = arr;
    tree.assign(4 * n, 0);
    build(0, 0, n - 1);
  }

  int rmq(int l, int r) { return rangeMinQuery(0, 0, n - 1, l, r); }

  void update(int pos, int val) {
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
    int t, x, y;
    cin >> t >> x >> y;
    x--;

    if (t == 1) {
      segTree.update(x, y);
    } else {
      y--;
      cout << segTree.rmq(x, y) << endl;
    }
  }

  return 0;
}
