#include <algorithm>
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

int f(int x, int y, int z, int n, const vi &a) {
  vector<vll> dp(n, vll(n, INT_MAX));

  for (int i = 0; i < n; i++) {
    dp[i][i + 1] = (a[i] * x + a[i + 1] * y + z) % 50;
  }

  max_heap(int) mp;
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    vi a(n);

    each(it, a) cin >> it;
  }
}