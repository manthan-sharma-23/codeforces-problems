#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProduct(int n) {
    string m = to_string(n);
    priority_queue<int> pq;

    for (char c : m)
      pq.push(c - '0');

    int sum = pq.top();
    pq.pop();
    sum *= pq.top();
    return sum;
  }
};
