#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vi vector<int>

class Solution {
public:
  int m, n;
  const vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  // Precompute fire spread time
  vector<vi> getFireTime(vector<vector<int>> &grid) {
    vector<vi> fire(m, vi(n, INT_MAX));
    queue<pii> q;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) {
          q.push({i, j});
          fire[i][j] = 0;
        }

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (auto [dx, dy] : directions) {
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] != 2 &&
            fire[nx][ny] == INT_MAX) {
          fire[nx][ny] = fire[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }

    return fire;
  }

  bool bfs(vector<vector<int>> &grid, vector<vi> &fireTime, int wait) {
    if (wait >= fireTime[0][0])
      return false;

    vector<vi> vis(m, vi(n, INT_MAX));
    queue<pii> q;
    q.push({0, 0});
    vis[0][0] = wait;

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (auto [dx, dy] : directions) {
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] != 2) {
          int nextTime = vis[x][y] + 1;
          if (nextTime < vis[nx][ny] && nextTime < fireTime[nx][ny]) {
            vis[nx][ny] = nextTime;
            q.push({nx, ny});
          }
        }
      }
    }

    int px = m - 1, py = n - 1;
    if (vis[px][py] == INT_MAX)
      return false;

    return vis[px][py] < fireTime[px][py] || fireTime[px][py] == INT_MAX;
  }

  int maximumMinutes(vector<vector<int>> &grid) {
    m = grid.size();
    n = grid[0].size();

    auto fireTime = getFireTime(grid);

    if (bfs(grid, fireTime, (int)1e9))
      return 1e9;

    int l = 0, h = m * n, res = -1;
    if (!bfs(grid, fireTime, 0)) {
      return -1;
    } else
      res = 0;

    while (l <= h) {
      int mid = l + (h - l) / 2;
      if (bfs(grid, fireTime, mid)) {
        res = mid;
        l = mid + 1;
      } else {
        h = mid - 1;
      }
    }

    return res;
  }
};
