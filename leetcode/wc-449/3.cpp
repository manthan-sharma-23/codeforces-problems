#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  vector<vector<int>> adj;
  vector<int> groupSize;
  vector<bool> isCycle;
  vector<int> roots;
  vector<int> value;
  vector<int> nodeToGroup;

  void dfs(int node, int parent, const int groupId, vector<bool> &visited) {
    visited[node] = true;
    groupSize[groupId]++;
    nodeToGroup[node] = groupId;

    for (int neighbor : adj[node]) {
      if (!visited[neighbor]) {
        dfs(neighbor, node, groupId, visited);
      } else if (neighbor != parent) {
        isCycle[groupId] = true;
      }
    }
  }

  vector<int> linearChainPath(int node, int parent, int start) {
    vector<int> left, right;

    for (int child : adj[node]) {
      if (child == parent)
        continue;

      if (left.empty()) {
        left = linearChainPath(child, node, start);
      } else if (right.empty()) {
        right = linearChainPath(child, node, start);
      }
    }

    if (node == start) {
      left.push_back(node);
      reverse(right.begin(), right.end());
      left.insert(left.end(), right.begin(), right.end());
    } else {
      left.push_back(node);
    }
    return left;
  }

  void bfsAssignCycle(int start, vector<bool> &visited, int &currentValue,
                      const int gid) {
    queue<int> q;

    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
      int sz = q.size();
      vector<int> currentLevel;
      for (int i = 0; i < sz; ++i) {
        int node = q.front();
        q.pop();
        currentLevel.push_back(node);

        for (int neighbor : adj[node]) {
          if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
          }
        }
      }

      reverse(currentLevel.begin(), currentLevel.end());
      for (int child : currentLevel) {
        value[child] = currentValue--;
      }
    }
  }

  void assignChain(int start, int &currentVal, const int gid) {
    vector<int> linearChain = linearChainPath(start, -1, start);
    int n = linearChain.size();
    int mid = n / 2;

    value[linearChain[mid]] = currentVal--;

    int left = mid - 1;
    int right = mid + 1;
    bool toLeft = true;

    if (n % 2 == 0) {
      int leftLen = mid;
      int rightLen = n - mid - 1;
      toLeft = leftLen >= rightLen;
    }

    while (left >= 0 || right < n) {
      if (toLeft && left >= 0) {
        value[linearChain[left--]] = currentVal--;
      } else if (!toLeft && right < n) {
        value[linearChain[right++]] = currentVal--;
      }
      toLeft = !toLeft;
    }
  }

  ll maxScore(int n, vector<vector<int>> &edges) {
    adj.assign(n, {});
    groupSize.assign(n, 0);
    isCycle.assign(n, false);
    roots.assign(n, -1);
    value.assign(n, 0);
    nodeToGroup.assign(n, 0);

    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    int groupId = 0;

    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        dfs(i, -1, groupId, visited);
        roots[groupId] = i;
        groupId++;
      }
    }

    vector<int> groupOrder;
    for (int i = 0; i < groupId; ++i)
      groupOrder.push_back(i);

    sort(groupOrder.begin(), groupOrder.end(), [&](int a, int b) {
      if (isCycle[a] == isCycle[b]) {
        return groupSize[a] > groupSize[b];
      }
      return isCycle[a] > isCycle[b];
    });

    fill(visited.begin(), visited.end(), false);
    int currentValue = n;

    for (int gid : groupOrder) {
      int root = roots[gid];
      if (!visited[root]) {
        if (isCycle[gid])
          bfsAssignCycle(root, visited, currentValue, gid);
        else
          assignChain(root, currentValue, gid);
      }
    }

    for (int i = 0; i < n; i++) {

      cout << i << " " << value[i] << endl;
    }

    return calculateScore(edges);
  }

  ll calculateScore(const vector<vector<int>> &edges) {
    ll score = 0;
    for (const auto &e : edges) {
      int u = e[0], v = e[1];
      score += 1LL * value[u] * value[v];
    }
    return score;
  }
};
