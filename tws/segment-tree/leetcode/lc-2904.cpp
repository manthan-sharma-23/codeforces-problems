#include <bits/stdc++.h>

using namespace std;

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

class Solution {
public:
  vector<int> leftmostBuildingQueries(vector<int> &heights,
                                      vector<vector<int>> &queries) {
    int n = heights.size();

    SegmentTree segTree(heights);

    vector<int> res;
    for (auto query : queries) {
      int l = query[0], r = query[1];
      int maxH = max(heights[r], heights[l]);

      if (l > r)
        swap(l, r);

      if (l == r) {
        res.push_back(l);
        continue;
      }
      if (heights[r] > heights[l]) {
        res.push_back(r);
        continue;
      }

      int low = r + 1, high = n - 1, b = -1;
      while (low <= high) {
        int mid = low + (high - low) / 2;

        if (heights[segTree.rmiq(low, mid)] > maxH) {
          b = mid;
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }

      res.push_back(b);
    }

    return res;
  }
};