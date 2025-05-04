#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long putMarbles(vector<int> &weights, int k) {
    int n = weights.size();

    vector<int> P;
    for (int i = 0; i < n - 1; i++) {
      P.push_back(weights[i] + weights[i + 1]);
    }

    sort(P.begin(), P.end());

    long long mini = 0, maxi = 0;

    for (int i = 0; i < k - 1; i++) {
      mini += P[i];
    }

    reverse(P.begin(), P.end());

    for (int i = 0; i < k - 1; i++) {
      maxi += P[i];
    }

    return maxi - mini;
  }
};