#include <bits/stdc++.h>
using namespace std;
// manthan's code

class DigitDP {
public:
  const int MODULO = 1e9 + 7;

  vector<int> convertToBase(long long number, int base) {
    vector<int> baseDigits;
    if (number == 0)
      return {0};
    while (number > 0) {
      baseDigits.push_back(number % base);
      number /= base;
    }
    reverse(baseDigits.begin(), baseDigits.end());
    return baseDigits;
  }

  int solve(int index, int prev, bool isTight, bool isZero, vector<int> &digits,
            int base, vector<vector<vector<vector<int>>>> &cache) {

    if (index == digits.size()) {
      return isZero ? 0 : 1;
    }

    if (cache[index][prev][isTight][isZero] != -1) {
      return cache[index][prev][isTight][isZero];
    }

    int upper = isTight ? digits[index] : base - 1;
    int totalWays = 0;

    for (int digit = 0; digit <= upper; ++digit) {
      if (!isZero && digit < prev)
        continue;

      int newPrev = (isZero && digit == 0) ? 0 : digit;
      bool newTight = isTight && (digit == upper);
      bool newZero = isZero && (digit == 0);

      totalWays = (totalWays + solve(index + 1, newPrev, newTight, newZero,
                                     digits, base, cache)) %
                  MODULO;
    }

    return cache[index][prev][isTight][isZero] = totalWays;
  }

  int countValid(long long value, int base) {
    vector<int> digits = convertToBase(value, base);
    vector<vector<vector<vector<int>>>> dpMemo(
        digits.size() + 1,
        vector<vector<vector<int>>>(
            base + 1, vector<vector<int>>(2, vector<int>(2, -1))));
    return solve(0, 0, true, true, digits, base, dpMemo);
  }

  int countInRange(const string &low, const string &high, int base) {
    long long lowVal = stoll(low);
    long long highVal = stoll(high);

    int result =
        (countValid(highVal, base) - countValid(lowVal - 1, base)) % MODULO;
    if (result < 0)
      result += MODULO;
    return result;
  }
};
