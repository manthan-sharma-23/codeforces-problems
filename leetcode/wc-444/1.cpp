#include <algorithm>
#include <climits>
#include <vector>
// manthans code
using namespace std;

class Solution {
public:
  int minimumPairRemoval(vector<int> &nums) {
    int oprs = 0;
    while (true) {
      if (is_sorted(nums.begin(), nums.end())) {
        break;
      }

      int miniSum = INT_MAX;
      int mergingIndex = 0;

      for (int i = 0; i < nums.size() - 1; ++i) {
        int current_sum = nums[i] + nums[i + 1];
        if (current_sum < miniSum) {
          miniSum = current_sum;
          mergingIndex = i;
        }
      }

      nums[mergingIndex] = miniSum;
      nums.erase(nums.begin() + mergingIndex + 1);
      oprs++;
    }
    return oprs;
  }
};