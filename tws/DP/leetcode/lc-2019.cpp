#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  set<int> st;

  // Recursive function to compute all possible results from different
  // parenthesizations
  vector<int> compute(const string &s, int i, int j) {
    vector<int> res;

    string sub = s.substr(i, j - i + 1);
    bool isNumber = true;
    for (char c : sub) {
      if (!isdigit(c)) {
        isNumber = false;
        break;
      }
    }

    if (isNumber) {
      int num = stoi(sub);
      res.push_back(num);
      st.insert(num);
      return res;
    }

    for (int k = i; k <= j; k++) {
      if (s[k] == '+' || s[k] == '*') {
        vector<int> left = compute(s, i, k - 1);
        vector<int> right = compute(s, k + 1, j);
        for (int l : left) {
          for (int r : right) {
            int val = (s[k] == '+') ? (l + r) : (l * r);
            res.push_back(val);
            st.insert(val);
          }
        }
      }
    }

    return res;
  }

  // Evaluates the expression using correct BODMAS (precedence)
  int evaluateBODMAS(string s) {
    vector<int> nums;
    vector<char> ops;
    int n = s.size();
    int i = 0;

    while (i < n) {
      if (isdigit(s[i])) {
        int num = 0;
        while (i < n && isdigit(s[i])) {
          num = num * 10 + (s[i] - '0');
          i++;
        }
        nums.push_back(num);
      } else {
        ops.push_back(s[i]);
        i++;
      }
    }

    // First pass: handle '*'
    vector<int> newNums;
    vector<char> newOps;
    newNums.push_back(nums[0]);

    for (int i = 0; i < ops.size(); i++) {
      if (ops[i] == '*') {
        int last = newNums.back();
        newNums.pop_back();
        newNums.push_back(last * nums[i + 1]);
      } else {
        newNums.push_back(nums[i + 1]);
        newOps.push_back(ops[i]);
      }
    }

    // Second pass: handle '+'
    int result = newNums[0];
    for (int i = 0; i < newOps.size(); i++) {
      result += newNums[i + 1];
    }

    return result;
  }

  int scoreOfStudents(string s, vector<int> &answers) {
    st.clear();
    compute(s, 0, s.size() - 1);

    int correct = evaluateBODMAS(s);
    int score = 0;

    for (int ans : answers) {
      if (ans == correct)
        score += 5;
      else if (st.count(ans))
        score += 2;
    }

    return score;
  }
};
