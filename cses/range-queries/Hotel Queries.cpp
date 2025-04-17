#include <bits/stdc++.h>
using namespace std;

class RangeMaxIndexSegTree {
private:
  int n;
  vector<int> &arr;
  vector<int> tree;

  void build(int index, int s, int e) {
    if (s == e) {
      tree[index] = s;
      return;
    }
    int mid = (s + e) / 2;
    build(index * 2, s, mid);
    build(index * 2 + 1, mid + 1, e);

    int left = tree[index * 2];
    int right = tree[index * 2 + 1];
    tree[index] = (arr[left] > arr[right]) ? left : right;
  }

  int rangeMax(int index, int s, int e, int l, int r) {
    if (s > r || e < l)
      return -1;
    if (s >= l && e <= r)
      return tree[index];

    int mid = (s + e) / 2;
    int left = rangeMax(index * 2, s, mid, l, r);
    int right = rangeMax(index * 2 + 1, mid + 1, e, l, r);

    if (left == -1)
      return right;
    if (right == -1)
      return left;
    return (arr[left] > arr[right]) ? left : right;
  }

  void update(int index, int s, int e, int pos, int val) {
    if (s == e) {
      arr[pos] += val;
      tree[index] = s;
      return;
    }
    int mid = (s + e) / 2;
    if (pos <= mid)
      update(index * 2, s, mid, pos, val);
    else
      update(index * 2 + 1, mid + 1, e, pos, val);

    int left = tree[index * 2];
    int right = tree[index * 2 + 1];
    tree[index] = (arr[left] > arr[right]) ? left : right;
  }

public:
  RangeMaxIndexSegTree(vector<int> &arr) : n(arr.size()), arr(arr) {
    tree.resize(4 * n);
    build(1, 0, n - 1);
  }

  int RMIQ(int l, int r) { return rangeMax(1, 0, n - 1, l, r); }

  void update(int pos, int val) { update(1, 0, n - 1, pos, val); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  RangeMaxIndexSegTree sgt(a);
  vector<int> ans;

  while (m--) {
    int group;
    cin >> group;

    int low = 0, high = n - 1, res = -1;

    while (low <= high) {
      int mid = (low + high) / 2;
      int rid = sgt.RMIQ(low, mid);

      if (a[rid] >= group) {
        res = rid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    if (res == -1) {
      ans.emplace_back(0);
    } else {
      ans.emplace_back(res + 1);
      sgt.update(res, -group);
    }
  }

  for (int v : ans)
    cout << v << " ";
  cout << "\n";
}
