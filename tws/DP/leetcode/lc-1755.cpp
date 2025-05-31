
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  void f(int idx, int currentSum, const vector<int> &nums, vector<int> &result,
         const int n) {
    if (idx == n) {
      result.push_back(currentSum);
      return;
    }
    f(idx + 1, currentSum, nums, result, n);
    f(idx + 1, currentSum + nums[idx], nums, result, n);
  }

  int minAbsDifference(vector<int> &nums, int goal) {
    int n = nums.size();

    vector<int> left, right;

    f(0, 0, nums, left, n / 2);
    f(n / 2, 0, nums, right, n);

    sort(right.begin(), right.end());

    int res = abs(goal);

    for (int s : left) {
      int remain = goal - s;

      auto it = lower_bound(right.begin(), right.end(), remain);
      if (it != right.end()) {
        res = min(res, abs(s + *it - goal));
      }
      if (it != right.begin()) {
        --it;
        res = min(res, abs(s + *it - goal));
      }
    }

    return res;
  }
};