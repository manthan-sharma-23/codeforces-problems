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
#define MOD 1000000007

class Solution {
public:
  int specialTriplets(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> suff;
    unordered_map<int, int> pref;

    for (int i = 1; i < n; ++i) {
      suff[nums[i]]++;
    }

    ll ans = 0;

    pref[nums[0]]++;

    for (int i = 1; i < n - 1; ++i) {
      int val = nums[i];

      suff[val]--;

      if (val * 2 <= INT_MAX) {
        ll cntL = pref[val * 2];
        ll cntR = suff[val * 2];

        ans = (ans + (cntL * cntR) % MOD) % MOD;
      }

      pref[val]++;
    }

    return ans;
  }
};