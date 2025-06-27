#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<tuple<int, int, int>> customers; // (arrival, departure, index)
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    customers.emplace_back(a, b, i);
  }

  sort(customers.begin(), customers.end());

  // Min-heap: (end_time, room_number)
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

  vector<int> result(n);
  int room_count = 0;

  for (auto &[start, end, index] : customers) {
    if (!pq.empty() && pq.top().first < start) {
      auto [old_end, room] = pq.top();
      pq.pop();
      result[index] = room;
      pq.emplace(end, room);
    } else {
      ++room_count;
      result[index] = room_count;
      pq.emplace(end, room_count);
    }
  }

  cout << room_count << '\n';
  for (int r : result)
    cout << r << ' ';
  cout << '\n';
}
