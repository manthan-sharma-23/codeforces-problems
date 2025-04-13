#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int uniqueXorTriplets(vector<int> &nums) {
    int n = nums.size();
    const int maxxor = 2048;
    vector<bool> pairXor(maxxor + 1, false);

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        pairXor[nums[i] ^ nums[j]] = true;
      }
    }

    vector<bool> result(maxxor + 1, false);
    for (int i = 0; i < n; i++) {
      for (int x = 0; x <= maxxor; x++) {
        if (pairXor[x]) {
          result[x ^ nums[i]] = true;
        }
      }
    }

    return count(result.begin(), result.end(), true);
  }
};
