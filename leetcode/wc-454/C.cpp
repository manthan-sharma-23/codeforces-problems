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
  ll maximumProduct(vector<int> &nums, int m) {
    int n = nums.size();
    vi prefMax(n, 0);
    vi prefMin(n, INT_MAX);

    prefMax[0] = nums[0], prefMin[0] = nums[0];
    for (int i = 1; i < n; i++) {
      prefMax[i] = max(nums[i], prefMax[i - 1]);
      prefMin[i] = min(nums[i], prefMin[i - 1]);
    }

    ll ans = LLONG_MIN;
    for (int i = m - 1; i < n; i++) {
      ans = max({ans, (ll)nums[i] * prefMax[i - m + 1],
                 (ll)nums[i] * prefMin[i - m + 1]});
    }

    return ans;
  }
};