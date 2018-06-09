#include <utility.h>
using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
	if (matrix.empty() || matrix[0].empty())
	  return false;
	int rowSize = matrix.size();
	int columnSize = matrix[0].size();
	int mid;
	int low = 0;
	int high = rowSize*columnSize;
	std::pair<int, int> midIndex;
	int midValue;
	while (high - low > 1) {
	  mid = (low + high)/2;
	  getIndex(columnSize, mid, midIndex);
	  midValue = matrix[midIndex.first][midIndex.second];
	  if (midValue <= target)
		low = mid;
	  else
		high = mid;
	}

	getIndex(columnSize, low, midIndex);
	midValue = matrix[midIndex.first][midIndex.second];
	if (midValue==target)
	  return true;
	else
	  return false;
  }

  inline void getIndex(const int row, const int seq, std::pair<int, int> &res) {
	res.first = seq/row;
	res.second = seq%row;
  };
};

int main() {
  vector<vector<int>> matrix{
	  {1, 3, 5, 7},
	  {10, 11, 16, 20},
	  {23, 30, 34, 50}
  };
  bool res = Solution().searchMatrix(matrix, 11);
  std::cout << res;
}
