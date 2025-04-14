#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
  int n;
  vector<int> node;

  void build(int index, int start, int last, const vector<int> &nums) {
    if (start == last) {
      node[index] = nums[start];
    } else {
      int mid = start + (last - start) / 2;
      build(2 * index, start, mid, nums);
      build(2 * index + 1, mid + 1, last, nums);

      node[index] = node[2 * index] + node[2 * index + 1];
    }
  }

  int query(int index, int s, int e, int l, int r) {

    if (r < s || e < l) {
      return 0;
    }

    if (l <= s && e <= r) {
      return node[index];
    }

    int mid = s + (e - s) / 2;
    int left = query(2 * index, s, mid, l, r);
    int right = query(2 * index + 1, mid + 1, e, l, r);

    return left + right;
  }

  void update(int index, int s, int e, int pos, int newVal) {
    if (s == e) {
      node[index] = newVal;
      return;
    }

    int mid = s + (e - s) / 2;
    if (pos <= mid) {
      update(2 * index, s, mid, pos, newVal);
    } else {
      update(2 * index + 1, mid + 1, e, pos, newVal);
    }

    node[index] = node[2 * index] + node[2 * index + 1];
  }

public:
  SegmentTree(const vector<int> &input) {
    n = input.size();
    node.resize(4 * n, 0);

    build(1, 0, n - 1, input);
  }

  int query(int l, int r) { return query(1, 0, n - 1, l, r); }

  void update(int pos, int val) { update(1, 0, n - 1, pos, val); }
};

int main() {
  vector<int> arr = {1, 2, 5, 5, 7, 8, 9};

  SegmentTree segTree(arr);

  cout << segTree.query(0, 3) << endl;
  segTree.update(2, 4);
  cout << segTree.query(0, 3) << endl;
}