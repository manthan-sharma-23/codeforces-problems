#include <bits/stdc++.h>

using namespace std;

//  build the minimum for the same or ask GPT
class SegmentTree {
private:
  vector<int> arr;
  vector<int> tree;
  const int n;

  void build(int index, int s, int e) {
    if (s == e) {
      tree[index] = s;
      return;
    }
    int mid = s + (e - s) / 2;

    build(2 * index + 1, s, mid);
    build(2 * index + 2, mid + 1, e);

    if (arr[tree[2 * index + 1]] > arr[tree[2 * index + 2]]) {
      tree[index] = tree[2 * index + 1];
    } else {
      tree[index] = tree[2 * index + 2];
    }
  }

  int rangeMaxIndexQuery(int index, int s, int e, int l, int r) {
    if (e < l || s > r)
      return -1;

    if (s >= l && e <= r)
      return tree[index];

    int mid = s + (e - s) / 2;

    int left = rangeMaxIndexQuery(2 * index + 1, s, mid, l, r);
    int right = rangeMaxIndexQuery(2 * index + 2, mid + 1, e, l, r);

    if (left == -1)
      return right;
    if (right == -1)
      return left;

    return arr[left] > arr[right] ? left : right;
  }

public:
  SegmentTree(vector<int> &arr) : n(arr.size()) {
    this->arr = arr;
    tree.assign(4 * n, 0);

    build(0, 0, n - 1);
  }

  int rmiq(int l, int r) { return rangeMaxIndexQuery(0, 0, n - 1, l, r); }
};