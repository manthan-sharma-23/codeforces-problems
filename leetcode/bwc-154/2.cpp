#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countBits(int n) {
    if (n == 0)
      return 1;
    return floor((double)log2(n)) + 1;
  }

  int uniqueXorTriplets(vector<int> &nums) {
    int n = nums.size();

    if (n == 1)
      return 1;
    if (n == 2)
      return 2;

    return pow(2, countBits(n));
  }
};
