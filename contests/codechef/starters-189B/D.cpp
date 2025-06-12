#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int testCases;
  cin >> testCases;

  while (testCases--) {
    int size;
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
      cin >> arr[i];
    }

    long long totalCount = 0;

    for (int i = 0; i < size; ++i) {
      int lastChosen = -1;

      for (int j = i; j < size; ++j) {
        int currentValue = arr[j];
        int maxAllowed = (currentValue - 1) / 2;

        if (lastChosen < maxAllowed) {
          lastChosen += 1;
          totalCount += 1;
        } else if (lastChosen < currentValue) {
          lastChosen = currentValue;
          totalCount += 1;
        } else {
          break;
        }
      }
    }

    cout << totalCount << '\n';
  }

  return 0;
}
