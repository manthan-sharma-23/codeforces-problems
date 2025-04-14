#include <bits/stdc++.h>

using namespace std;

class NumArray {
private:
  const int n;
  vector<int> sgt;

  int sumRange(int index, int s, int e, int l, int r) {

    if (r < s || l > e)
      return 0;

    if (s >= l && e <= r) {
      return sgt[index];
    }

    int mid = s + (e - s) / 2;
    int left = sumRange(2 * index, s, mid, l, r);
    int right = sumRange(2 * index + 1, mid + 1, e, l, r);

    return left + right;
  }

  void update(int index, int s, int e, int pos, int val) {
    if (s == e) {
      sgt[index] = val;
      return;
    }

    int mid = s + (e - s) / 2;

    if (pos <= mid)
      update(2 * index, s, mid, pos, val);
    else
      update(2 * index + 1, mid + 1, e, pos, val);

    sgt[index] = sgt[2 * index] + sgt[2 * index + 1];
  }

  void build(int index, int s, int e, const vector<int> &nums) {
    if (s == e) {
      sgt[index] = nums[s];
      return;
    }

    int mid = s + (e - s) / 2;
    build(2 * index, s, mid, nums);
    build(2 * index + 1, mid + 1, e, nums);

    sgt[index] = sgt[2 * index] + sgt[2 * index + 1];
  }

public:
  NumArray(vector<int> &nums) : n(nums.size()) {
    sgt.resize(4 * n, 0);

    build(1, 0, n - 1, nums);
  }

  void update(int index, int val) { update(1, 0, n - 1, index, val); }

  int sumRange(int left, int right) {
    return sumRange(1, 0, n - 1, left, right);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */