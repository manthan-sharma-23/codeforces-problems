#include <bits/stdc++.h>
using namespace std;

#define FIO ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'

void solve() {
    int n, w;
    cin >> n >> w;

    vi wt(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> wt[i] >> v[i];
    }

    const int maxV = 1e5 + 5;
    const ll INF = 1e15;

    // dp[i][j] = min weight to get value j using first i items
    vector<vector<ll>> dp(n + 1, vector<ll>(maxV, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < maxV; j++) {
            // don't take item i
            dp[i][j] = dp[i - 1][j];
            // take item i if value fits
            if (v[i] <= j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + wt[i]);
            }
        }
    }

    int profit = 0;
    for (int i = 0; i < maxV; i++) {
        if (dp[n][i] <= w) {
            profit = i;
        }
    }

    cout << profit << endl;
}

int main() {
    FIO
    solve();
    return 0;
}
