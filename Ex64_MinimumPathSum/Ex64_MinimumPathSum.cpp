#include <utility.h>

using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>> &grid) {
	int row = grid.size();
	int column = grid[0].size();
	vector<int> columnMin(row, 0);
	columnMin[0] = grid[0][0];
	for (int i = 1; i < row; i++) {
	  columnMin[i] = columnMin[i - 1] + grid[i][0];
	}

	for (int i = 1; i < column; i++) {
	  columnMin[0] = columnMin[0] + grid[0][i];
	  for (int j = 1; j < row; j++) {
		columnMin[j] = grid[j][i] + std::min(columnMin[j - 1], columnMin[j]);
	  }
	}
	return columnMin[row - 1];
  }
};

int main() {
  vector<vector<int>> grid{
	  {1, 3, 1},
	  {1, 5, 1},
	  {4, 2, 1}
  };
  int res = Solution().minPathSum(grid);
  std::cout << res;
}
