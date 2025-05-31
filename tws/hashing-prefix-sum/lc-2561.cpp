#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define F first
#define S second
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2, custom_hash>
#define hash_set(T) unordered_set<T>
#define loop(i, a, b, step) for (int i = (a); i < (b); i += step)
#define asc(v) sort((v).begin(), (v).end())
#define dsc(v) sort((v).rbegin(), (v).rend())
#define ll long long
#define vi vector<int>
#define vll vector<ll>

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

class Solution {
public:
  long long minCost(vector<int> &basket1, vector<int> &basket2) {

    unordered_map<int, int> mp1, mp2;
    hash_set(int) st;

    for (int it : basket1) {
      st.insert(it);
      mp1[it]++;
    }
    for (int it : basket2) {
      st.insert(it);
      mp2[it]++;
    }

    vi nsw1, nsw2;

    for (int num : st) {
      if ((mp1[num] + mp2[num]) % 2 != 0)
        return -1;

      if (mp1[num] == mp2[num])
        continue;

      if (mp2[num] > mp1[num]) {
        int diff = (mp2[num] - mp1[num]);
        if (diff % 2 != 0)
          return -1;
        for (int i = 1; i <= diff / 2; i++) {
          nsw2.push_back(num);
        }
      } else {
        int diff = (mp1[num] - mp2[num]);
        if (diff % 2 != 0)
          return -1;
        for (int i = 1; i <= diff / 2; i++) {
          nsw1.push_back(num);
        }
      }
    }

    for (auto it : nsw1)
      cout << it << " ";
    cout << endl;
    for (auto it : nsw2)
      cout << it << " ";
    cout << endl;

    asc(nsw1), dsc(nsw2);

    if (nsw1.size() != nsw2.size())
      return -1;

    ll cost1 = 0, cost2 = 0;

    for (int i = 0; i < nsw1.size(); i++) {
      cost1 += min(nsw1[i], nsw2[i]);
    }

    asc(nsw2), dsc(nsw1);
    for (int i = 0; i < nsw1.size(); i++) {
      cost2 += min(nsw1[i], nsw2[i]);
    }

    return min(cost1, cost2);
  }
};