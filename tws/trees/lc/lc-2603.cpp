#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define F first
#define S second
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2>
#define hash_set(T) unordered_set<T>
#define loop(i, a, b, step) for (int i = (a); i < (b); i += step)
#define asc(v) sort((v).begin(), (v).end())
#define dsc(v) sort((v).rbegin(), (v).rend())
#define ll long long
#define vi vector<int>
#define vll vector<ll>

class Solution {
public:
  int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
    int n = edges.size() + 1;

    vector<bool> pruned(n, 0);

    vector<hash_set(int)> adj(n, hash_set(int)());
    for (auto e : edges) {
      int u = e[0], v = e[1];

      adj[u].insert(v);
      adj[v].insert(u);
    }

    queue<int> q;

    for (int i = 0; i < n; ++i) {
      if (coins[i] == 0 && adj[i].size() == 1) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      each(child, adj[node]) {
        adj[child].erase(node);

        if (coins[child] == 0 && adj[child].size() == 1) {
          q.push(child);
        }
      }

      adj[node].clear();
    }

    int itr = 2;
    while (itr--) {
      vi leafs;

      for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
          leafs.push_back(i);
        }
      }

      each(leaf, leafs) {
        each(child, adj[leaf]) { adj[child].erase(leaf); }
        adj[leaf].clear();
      }
    }

    int result = 0;
    for (auto &edge : edges) {
      int nodeA = edge[0], nodeB = edge[1];
      if (adj[nodeA].size() && adj[nodeB].size()) {
        result += 2; // Each remaining edge contributes 2 to the answer
      }
    }

    return result;
  }
};