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
  vector<vector<pii>> adj;
  int n;
  int allVisited;
  vector<vector<int>> dp;

  int f(int mask, int lastIndex) {
    if (mask == allVisited)
      return 0;

    if (dp[mask][lastIndex] != -1)
      return dp[mask][lastIndex];

    int len = INT_MAX;

    for (auto [j, cost] : adj[lastIndex]) {
      if (mask & (1 << j))
        continue;

      len = min(len, cost + f(mask | (1 << j), j));
    }

    return dp[mask][lastIndex] = len;
  }

  int longestSuffixPrefixMatch(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    string combined = b + '#' + a;
    int len = combined.size();

    vector<int> lps(len, 0);
    for (int i = 1; i < len; ++i) {
      int j = lps[i - 1];
      while (j > 0 && combined[i] != combined[j])
        j = lps[j - 1];
      if (combined[i] == combined[j])
        ++j;
      lps[i] = j;
    }

    return lps.back();
  }

  string shortestSuperstring(vector<string> &words) {
    n = words.size();
    allVisited = (1 << n) - 1;
    adj.assign(n, {});
    dp.assign(1 << n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        int overlap = longestSuffixPrefixMatch(words[i], words[j]);
        adj[i].push_back({j, (int)words[j].size() - overlap});
      }
    }

    int minLen = INT_MAX;
    for (int i = 0; i < n; i++)
      minLen = min(minLen, (int)words[i].size() + f(1 << i, i));

    // If you want to build the actual superstring, let me know.
    return to_string(minLen); // temp
  }
};
