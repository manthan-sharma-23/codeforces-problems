#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> specialGrid(int N) {
    if (N < 0) {
      return {};
    }

    if (N == 0) {
      return {{0}};
    }

    vector<vector<int>> smallerGrid = specialGrid(N - 1);
    int subgridSize = smallerGrid.size();
    int newSize = subgridSize * 2;
    int quadrantValueOffset = subgridSize * subgridSize;

    vector<vector<int>> resultGrid(newSize, vector<int>(newSize));

    fillGridQuadrants(resultGrid, smallerGrid, subgridSize,
                      quadrantValueOffset);

    return resultGrid;
  }

private:
  void fillGridQuadrants(vector<vector<int>> &result,
                         const vector<vector<int>> &source, int size,
                         int offset) {
    copyQuadrant(result, source, 0, size, size, 0);
    copyQuadrant(result, source, size, size, size, offset);
    copyQuadrant(result, source, size, 0, size, 2 * offset);
    copyQuadrant(result, source, 0, 0, size, 3 * offset);
  }

  void copyQuadrant(vector<vector<int>> &dest,
                    const vector<vector<int>> &source, int startRow,
                    int startCol, int size, int valueOffset) {
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        dest[startRow + i][startCol + j] = source[i][j] + valueOffset;
      }
    }
  }
};