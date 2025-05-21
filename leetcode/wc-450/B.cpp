#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  using ll = long long;

  int sumOfDigits(int n) {
    int sum = 0;
    n = abs(n);
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }

  int minSwaps(vector<int> &nums) {
    unordered_map<int, ll> digitSum;

    for (auto it : nums) {
      digitSum[it] = sumOfDigits(it);
    }

    vector<int> a = nums;

    sort(a.begin(), a.end(), [&digitSum](int a, int b) {
      if (digitSum[a] == digitSum[b]) {
        return a < b;
      } else {
        return digitSum[a] < digitSum[b];
      }
    });

    unordered_map<int, queue<int>> valueToIndices;
    for (int i = 0; i < a.size(); ++i) {
      valueToIndices[a[i]].push(i);
    }

    vector<int> indexMap(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      indexMap[i] = valueToIndices[nums[i]].front();
      valueToIndices[nums[i]].pop();
    }

    vector<bool> visited(nums.size(), false);
    int swaps = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (visited[i] || indexMap[i] == i)
        continue;

      int cycle_size = 0;
      int j = i;
      while (!visited[j]) {
        visited[j] = true;
        j = indexMap[j];
        cycle_size++;
      }
      if (cycle_size > 1) {
        swaps += cycle_size - 1;
      }
    }

    return swaps;
  }
};
