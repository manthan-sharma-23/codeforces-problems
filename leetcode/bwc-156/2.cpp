#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums) {
    int n = nums.size();
    vector<int> nextSmaller(n, n);
    unordered_map<int, int> lastProcessedIndex;
    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
      while (!st.empty() && nums[i] <= nums[st.top()]) {
        st.pop();
      }
      if (!st.empty()) {
        nextSmaller[i] = st.top();
      }
      st.push(i);
    }

    int operations = 0;

    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0)
        continue;
      if (i >= lastProcessedIndex[nums[i]]) {
        ++operations;
        lastProcessedIndex[nums[i]] = nextSmaller[i];
      }
    }

    return operations;
  }
};