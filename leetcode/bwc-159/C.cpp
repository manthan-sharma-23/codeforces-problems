#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> adj;
    vector<int> parent;
    vector<long long> pathSum;
    vector<long long> nodeDeficit;
    vector<long long> subtreeVal;
    long long maxPathSum;
    int increaseCount;

    void dfsComputeSums(int u, int p, const vector<int>& cost) {
        parent[u] = p;
        for (int v : adj[u]) {
            if (v == p) continue;
            pathSum[v] = pathSum[u] + cost[v];
            dfsComputeSums(v, u, cost);
        }
    }

    long long dfsComputeVals(int u, int p) {
        bool isLeaf = (u == 0 ? adj[u].empty()
                             : adj[u].size() == 1);
        if (isLeaf) {
            subtreeVal[u] = maxPathSum - pathSum[u];
            return subtreeVal[u];
        }
        long long firstDef = LLONG_MIN;
        bool uniform = true;
        for (int v : adj[u]) {
            if (v == p) continue;
            long long d = dfsComputeVals(v, u);
            if (firstDef == LLONG_MIN) {
                firstDef = d;
            } else if (d != firstDef) {
                uniform = false;
            }
        }
        if (!uniform || firstDef < 0) {
            subtreeVal[u] = -1;
        } else {
            subtreeVal[u] = firstDef;
        }
        return subtreeVal[u];
    }

public:
    int minIncrease(int n_, vector<vector<int>>& edges, vector<int>& cost) {
        n = n_;
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        parent.assign(n, -1);
        pathSum.assign(n, 0);
        subtreeVal.assign(n, -1);

        pathSum[0] = cost[0];
        dfsComputeSums(0, -1, cost);

        maxPathSum = 0;
        for (int u = 0; u < n; ++u) {
            bool isLeaf = (u == 0 ? adj[u].empty()
                                 : adj[u].size() == 1);
            if (isLeaf) {
                maxPathSum = max(maxPathSum, pathSum[u]);
            }
        }

        dfsComputeVals(0, -1);

        increaseCount = 0;
        for (int u = 0; u < n; ++u) {
            if (subtreeVal[u] > 0) {
                int p = parent[u];
                if (p == -1 || subtreeVal[p] != subtreeVal[u]) {
                    ++increaseCount;
                }
            }
        }
        return increaseCount;
    }
};
