#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxResult(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> dp(n, INT_MIN);

    dp[0] = nums[0];

    set<pair<int, int>> st; //  dp[l] , l

    int j = 0;
    for (int i = 1; i < n; i++) {

      while (st.size() > k - 1) {
        st.erase({dp[j], j});
        j++;
      }

      dp[i] = st.rbegin()->first + nums[i];

      st.insert({dp[i], i});
    }

    return dp[n - 1];
  }
};