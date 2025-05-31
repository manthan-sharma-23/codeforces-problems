#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define F first
#define S second
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2, custom_hash>
#define hash_set(T) unordered_set<T>
#define loop(i, a, b, step) for (int i = (a); i < (b); i += step)
#define asc(v) sort((v).begin(), (v).end())
#define dsc(v) sort((v).rbegin(), (v).rend())
#define ll long long
#define vi vector<int>
#define vll vector<ll>

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

class Solution {
public:
  vector<int> gridIllumination(int n, vector<vector<int>> &lamps,
                               vector<vector<int>> &queries) {

    hash_map(int, bool) rowc, colc, diagc;
    vector<pii> dirc = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1},
                        {0, 1}, {0, -1}, {1, 0},  {-1, 0}};

    hash_map(int, hash_set(int)) off;

    vi res;

    for (auto &lamp : lamps) {
      int f = lamp[1] - lamp[0];
      rowc[lamp[0]] = 1;
      colc[lamp[1]] = 1;
      diagc[n + lamp[1] - lamp[0]] = 1;
    }

    auto canOn = [&](int r, int c) {
      for (auto &dir : dirc) {
        int nr = r + dir.F, nc = c + dir.S;

        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
          if (off[nr].count(nc) > 0)
            return false;
        }
      }

      if (rowc[r] || colc[c] || diagc[n + c - r])
        return true;
      else
        return false;
    };

    for (auto &q : queries) {
      if (canOn(q[0], q[1])) {
        res.push_back(1);
      } else
        res.push_back(0);

      off[q[0]].insert(q[1]);
    }

    return res;
  }
};