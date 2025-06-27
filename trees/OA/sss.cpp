#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> tree[N];
int cnt[N], res[N], depth[N];
int up[N][20];  // For binary lifting
int tin[N], tout[N], timer;

void dfs_lca(int u, int p) {
    tin[u] = ++timer;
    up[u][0] = p;
    for (int i = 1; i < 20; ++i)
        up[u][i] = up[up[u][i-1]][i-1];

    for (int v : tree[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs_lca(v, u);
        }
    }
    tout[u] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = 19; i >= 0; --i)
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

void dfs_cnt(int u, int p) {
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs_cnt(v, u);
        cnt[u] += cnt[v];
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Read tree
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // Preprocess LCA
    dfs_lca(1, 1); // Root is 1

    // Handle paths
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        int l = lca(a, b);
        cnt[a] += 1;
        cnt[b] += 1;
        cnt[l] -= 1;
        if (up[l][0] != l) cnt[up[l][0]] -= 1;
    }

    // Propagate counts
    dfs_cnt(1, 1);

    // Output result
    for (int i = 1; i <= n; ++i)
        cout << cnt[i] << " ";
    cout << "\n";

    return 0;
}
