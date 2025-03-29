#include <vector>
using namespace std;

typedef vector<vector<int>> Mat;

Mat Identity(int n) {
  Mat I = vector<vector<int>>(n, vector<int>(n, 1));
  return I;
}

Mat I = Identity(4);