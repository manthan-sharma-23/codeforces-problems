

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
  int maximumPossibleSize(vector<int> &nums) {
    int n = nums.size();

    int size = 0;

    int i = 0;
    while (i < n) {
      size++;
      int major = nums[i++];
      while (nums[i] < major) {
        i++;
      }
    }

    return size;
  }
};
