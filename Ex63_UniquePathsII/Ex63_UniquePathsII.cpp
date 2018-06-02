#include <utility.h>

using namespace std;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
	int row = obstacleGrid.size();
	int column = obstacleGrid[0].size();
	std::vector<int> columnPaths(row, 0);

	if (obstacleGrid[0][0]==1 || obstacleGrid[row - 1][column - 1]==1)
	  return 0;

	columnPaths[0] = 1;
	bool isOsbtacle = false;
	for (int i = 1; i < row; i++) {
	  if (obstacleGrid[i][0]==0 && !isOsbtacle)
		columnPaths[i] = 1;
	  else {
		columnPaths[i] = 0;
		isOsbtacle = true;
	  }
	}

	for (int i = 1; i < column; i++) {
	  columnPaths[0] = obstacleGrid[0][i]==1 ? 0 : columnPaths[0];
	  for (int j = 1; j < row; j++) {
		columnPaths[j] = obstacleGrid[j][i]==1 ? 0 : (columnPaths[j] + columnPaths[j - 1]);
	  }
	}

	return columnPaths[row - 1];
  }
};

int main() {
  vector<vector<int>> grid{
	  {0, 0, 0, 0, 0},
	  {1, 0, 0, 0, 0},
	  {0, 0, 0, 0, 0},
	  {0, 0, 0, 0, 0}
  };

  int res = Solution().uniquePathsWithObstacles(grid);
  std::cout << res;
}

