#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  using pii = pair<int, int>;
  int R, C;
  const int ALPHA = 65;
  vector<vector<pii>> tp;
  vector<bool> used;

  bool in(int x, int y) { return x >= 0 && y >= 0 && x < R && y < C; }

  int minMoves(vector<string> &g) {
    R = g.size();
    C = g[0].size();
    tp.assign(26, {});
    used.assign(26, false);

    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j) {
        char c = g[i][j];
        if (c >= 'A' && c <= 'Z')
          tp[c - ALPHA].emplace_back(i, j);
      }

    const int INF = 1e9;
    vector<vector<int>> dist(R, vector<int>(C, INF));
    queue<pii> cur, nxt;

    dist[0][0] = 0;
    cur.emplace(0, 0);
    int d = 0;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    while (!cur.empty() || !nxt.empty()) {
      while (!cur.empty()) {
        auto [x, y] = cur.front();
        cur.pop();
        if (dist[x][y] != d)
          continue;
        if (x == R - 1 && y == C - 1)
          return d;

        char c = g[x][y];
        if (c >= 'A' && c <= 'Z') {
          int idx = c - ALPHA;
          if (!used[idx]) {
            used[idx] = true;
            for (auto &pr : tp[idx]) {
              int nx = pr.first, ny = pr.second;
              if (dist[nx][ny] > d) {
                dist[nx][ny] = d;
                cur.emplace(nx, ny);
              }
            }
          }
        }

        for (int k = 0; k < 4; ++k) {
          int nx = x + dx[k], ny = y + dy[k];
          if (in(nx, ny) && g[nx][ny] != '#' && dist[nx][ny] > d + 1) {
            dist[nx][ny] = d + 1;
            nxt.emplace(nx, ny);
          }
        }
      }
      swap(cur, nxt);
      ++d;
    }

    return -1;
  }
};
