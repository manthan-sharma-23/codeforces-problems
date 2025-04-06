#include <bits/stdc++.h>

using namespace std;

class Router {
private:
  int size;
  typedef vector<int> Address;
  queue<Address> q;
  unordered_map<string, bool> keys;
  unordered_map<int, vector<int>> mp;

  string Key(int a, int b, int c) {
    return to_string(a) + "_" + to_string(b) + "_" + to_string(c);
  }

public:
  Router(int memoryLimit) : size(memoryLimit) {}

  bool addPacket(int source, int destination, int timestamp) {
    string key = Key(source, destination, timestamp);
    if (keys[key])
      return false;

    keys[key] = true;

    if (q.size() == size) {
      Address topAddr = q.front();
      q.pop();

      string oldKey = Key(topAddr[0], topAddr[1], topAddr[2]);
      keys.erase(oldKey);

      int dest = topAddr[1], time = topAddr[2];
      auto &timestamps = mp[dest];

      auto it = lower_bound(timestamps.begin(), timestamps.end(), time);
      if (it != timestamps.end() && *it == time)
        timestamps.erase(it);

      if (timestamps.empty())
        mp.erase(dest);
    }

    q.push({source, destination, timestamp});
    mp[destination].push_back(timestamp);
    return true;
  }

  vector<int> forwardPacket() {
    if (q.empty())
      return {};

    Address topAddr = q.front();
    q.pop();

    string key = Key(topAddr[0], topAddr[1], topAddr[2]);
    keys.erase(key);

    int dest = topAddr[1], time = topAddr[2];
    auto &timestamps = mp[dest];

    auto it = lower_bound(timestamps.begin(), timestamps.end(), time);
    if (it != timestamps.end() && *it == time)
      timestamps.erase(it);

    if (timestamps.empty())
      mp.erase(dest);

    return topAddr;
  }

  int getCount(int destination, int startTime, int endTime) {
    if (mp.find(destination) == mp.end())
      return 0;

    auto &timestamps = mp[destination];
    return distance(
        lower_bound(timestamps.begin(), timestamps.end(), startTime),
        upper_bound(timestamps.begin(), timestamps.end(), endTime));
  }
};
