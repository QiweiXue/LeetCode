#include <utility.h>

using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>> &matrix) {
	int rowSize = matrix.size();
	int columnSize = matrix[0].size();
	bool column0 = false;
	bool row0 = false;
	for (int i = 0; i < rowSize; i++) {
	  if (matrix[i][0]==0) {
		column0 = true;
		break;
	  }
	}
	for (int j = 0; j < columnSize; j++) {
	  if (matrix[0][j]==0) {
		row0 = true;
		break;
	  }
	}
	for (int i = 1; i < rowSize; i++) {
	  for (int j = 1; j < columnSize; j++) {
		if (matrix[i][j]==0) {
		  matrix[i][0] = 0;
		  matrix[0][j] = 0;
		}
	  }
	}

	for (int i = 1; i < rowSize; i++) {
	  if (matrix[i][0]==0) {
		for (int j = 0; j < columnSize; j++)
		  matrix[i][j] = 0;
	  }
	}

	for (int j = 1; j < columnSize; j++) {
	  if (matrix[0][j]==0) {
		for (int i = 0; i < rowSize; i++)
		  matrix[i][j] = 0;
	  }
	}

	if (column0==true) {
	  for (int i = 0; i < rowSize; i++)
		matrix[i][0] = 0;
	}
	if (row0==true) {
	  for (int j = 0; j < columnSize; j++)
		matrix[0][j] = 0;
	}
  }
};

int main() {
  vector<vector<int>> matrix
	  {
		  {0, 1, 2, 0},
		  {3, 4, 5, 2},
		  {1, 3, 1, 5}
	  };
  Solution().setZeroes(matrix);
  printMatrix(matrix);
}

