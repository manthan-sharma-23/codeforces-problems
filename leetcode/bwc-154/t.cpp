#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  typedef long long ll;

  int uniqueXorTriplets(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    const int mxp = 2048;
    vector<vector<bool>> pp(4, vector<bool>(mxp, false));
    vector<vector<bool>> cc(4, vector<bool>(mxp, false));
    pp[0][0] = true;
    for (int cn : nums) {
      cc = pp;
      for (int x = 0; x < mxp; ++x) {
        if (pp[0][x ^ cn]) {
          cc[1][x] = true;
          cc[3][x] = true;
        }
        if (pp[1][x ^ cn])
          cc[2][x] = true;
        if (pp[2][x ^ cn])
          cc[3][x] = true;
      }

      pp = cc;
    }
    int ux = 0;
    for (int x = 0; x < mxp; ++x) {
      if (pp[3][x]) {
        ux++;
      }
    }
    return ux;
  }
};
