#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> parent, weight;

  DSU(int n) {
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    weight.assign(n, 0);
  }

  int find(int x, int y) {}
};

void solve() {
  int n, k;
  cin >> n >> k;

  DSU dsu(n);
  int c = 0;
  while (k--) {
    int t;
    cin >> t;

    int x, y;
    cin >> x >> y;

    if (x > n || y > n) {
      c++;
    } else if (t == 1) {
      if (x != y) {
      }
    } else {
      if (x == y)
        c++;
      else {
      }
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}