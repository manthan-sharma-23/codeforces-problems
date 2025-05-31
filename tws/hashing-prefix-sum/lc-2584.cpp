#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  const int MAXN = 1e6 + 1;
  vector<int> spf;
  void Sieve() {
    iota(spf.begin(), spf.end(), 0); // initialize spf[i] = i
    for (int i = 2; i * i < MAXN; ++i) {
      if (spf[i] == i) { // i is prime
        for (int j = i * i; j < MAXN; j += i) {
          if (spf[j] == j) {
            spf[j] = i;
          }
        }
      }
    }
  }

  vector<int> f(int n) {
    vector<int> res;
    while (n > 1) {
      res.push_back(spf[n]);
      n /= spf[n];
    }
    return res;
  }

  int findValidSplit(vector<int> &nums) {
    int n = nums.size();
    spf.resize(MAXN);
    Sieve();

    unordered_map<int, vector<int>> factors;
    for (int it : nums)
      factors[it] = f(it);

    vector<int> lastIndex(MAXN, -1);

    for (int i = 0; i < n; i++) {
      for (int fx : factors[nums[i]]) {
        lastIndex[fx] = i;
      }
    }

    int res = 0, i = 0;

    while (i <= res) {
      for (int fx : factors[nums[i]]) {
        res = max(lastIndex[fx], res);
      }
      i++;
    }

    return res;
  }
};