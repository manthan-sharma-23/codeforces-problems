#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int partitionDisjoint(vector<int> &nums) {
    int n = nums.size();
    int maxN = *max_element(nums.begin(), nums.end()) + 1;

    vector<int> lastIndex(maxN, -1), lastpref(maxN, -1);

    for (int i = 0; i < n; i++) {
      lastIndex[nums[i]] = i;
    }

    lastpref[1] = lastIndex[0];
    for (int i = 2; i < maxN; i++) {

      lastpref[i] = max(lastpref[i - 1], lastIndex[i - 1]);
    }

    int i = 0, res = 0;
    while (i <= res) {
      res = max(lastpref[nums[i]], res);
      i++;
    }

    return res;
  }
};