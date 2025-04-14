#include <bits/stdc++.h>

using namespace std;

void build(int index, int s, int e, int arr[], int node[]) {
  if (s == e) {
    node[index] = arr[s];
    return;
  }

  int mid = s + (e - s) / 2;

  build(2 * index, s, mid, arr, node);
  build(2 * index + 1, mid + 1, e, arr, node);

  node[index] = min(node[2 * index], node[2 * index + 1]);
}

int query(int index, int s, int e, int l, int r, int tree[]) {
  if (l > e || r < s)
    return INT_MAX;

  if (s >= l && e <= r)
    return tree[index];

  int mid = s + (e - s) / 2;
  int left = query(2 * index, s, mid, l, r, tree);
  int right = query(2 * index + 1, mid + 1, e, l, r, tree);

  return min(left, right);
}

int *constructST(int arr[], int n) {
  n = n;
  int *node = new int[4 * n];

  build(1, 0, n - 1, arr, node);

  return node;
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b) { return query(1, 0, n - 1, a, b, st); }