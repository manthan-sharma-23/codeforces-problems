#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SegmentTree {
private:
  int n;
  vector<ll> node;

  void build(int index, int start, int end, const vector<int> &nums) {
    if (start == end) {
      node[index] = nums[start];
    } else {
      int mid = start + (end - start) / 2;
      build(2 * index + 1, start, mid, nums);
      build(2 * index + 2, mid + 1, end, nums);
      node[index] = node[2 * index + 1] + node[2 * index + 2];
    }
  }

  ll query(int index, int s, int e, int l, int r) {
    if (r < s || e < l)
      return 0;
    if (l <= s && e <= r)
      return node[index];

    int mid = s + (e - s) / 2;
    ll left = query(2 * index + 1, s, mid, l, r);
    ll right = query(2 * index + 2, mid + 1, e, l, r);
    return left + right;
  }

  void update(int index, int s, int e, int pos, int newVal) {
    if (s == e) {
      node[index] = newVal;
      return;
    }

    int mid = s + (e - s) / 2;
    if (pos <= mid)
      update(2 * index + 1, s, mid, pos, newVal);
    else
      update(2 * index + 2, mid + 1, e, pos, newVal);

    node[index] = node[2 * index + 1] + node[2 * index + 2];
  }

public:
  SegmentTree(const vector<int> &input) {
    n = input.size();
    node.resize(4 * n, 0);
    build(0, 0, n - 1, input);
  }

  ll query(int l, int r) { return query(0, 0, n - 1, l, r); }

  void update(int pos, int val) { update(0, 0, n - 1, pos, val); }
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
      cout << segTree.query(x, y) << endl;
    }
  }

  return 0;
}
