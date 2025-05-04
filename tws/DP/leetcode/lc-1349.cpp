#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int m, n;

  using ll = long long;

  vector<int> v;
  vector<vector<ll>> dp;
  ll f(int i, ll mask) {
    if (i == m * n)
      return 0LL;

    ll maxStu = f(i + 1, mask);
    if (v[i] == 1) {
      if (i < n) {
        if (i == 0 || !(mask & (1 << (i - 1))))
          maxStu = max(maxStu, 1 + f(i + 1, mask | (1 << i)));
      } else {
        if ((((i % n == 0) && !(mask & (1 << (1 - n + 1)))) ||
             ((i % n == n - 1) && !(mask & (1 << (1 - n - 1)))) ||
             !(mask & (1 << (i - 1))) && !(mask & (1 << (i - n - 1)) &&
                                           !(mask & (1 << (i - n + 1)))))) {
          maxStu = max(maxStu, 1 + f(i + 1, mask | (1 << i)));
        }
      }
    }

    return maxStu;
  }

  int maxStudents(vector<vector<char>> &seats) {
    m = seats.size(), n = seats[0].size();
    int T = m * n;

    v.assign(m * n, 0);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        v[m * i + j] = seats[i][j] == '.';
      }
    }

    int allVisited = 1 << T;

    dp.assign(n * m, vector<ll>(allVisited, -1));

    return f(0, 0);
  }
};