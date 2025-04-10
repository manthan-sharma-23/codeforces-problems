#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  bool check(vector<int> &piles, int k, const int h) {
    int hours = 0;

    for (int n : piles) {
      hours += ceil((double)n / k);
    }

    return hours <= h;
  }

  int minEatingSpeed(vector<int> &piles, int h) {
    int n = piles.size();

    int low = 1, high = *max_element(piles.begin(), piles.end());

    int res = high;
    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (check(piles, mid, h)) {
        high = mid - 1;
        res = mid;
      } else {
        low = mid + 1;
      }
    }

    return res;
  }
};