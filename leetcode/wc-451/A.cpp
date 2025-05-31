using namespace std;

class Solution {
public:
  long long minCuttingCost(int n, int m, int k) {
    long long res = 0;

    if (n > k) {
      res += (k * (n - k));
    }
    if (m > k) {
      res += (k * (m - k));
    }

    return res;
  }
};