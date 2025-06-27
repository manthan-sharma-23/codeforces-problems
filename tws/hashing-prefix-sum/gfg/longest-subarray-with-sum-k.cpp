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
  int longestSubarray(vector<int> &arr, int k) {
    hash_map(int, int) mp;

    int n = arr.size();
    mp.clear();

    int pf = arr[0], len = 0;

    if (pf == k)
      len = 1;

    for (int i = 1; i < n; i++) {
      pf += arr[i];

      if (mp.find(k - pf) != mp.end()) {
        len = max(len, i - mp[k - pf] + 1);
      }

      if (mp.find(pf) == mp.end()) {
        mp[pf] = i;
      }
    }

    return len;
  }
};