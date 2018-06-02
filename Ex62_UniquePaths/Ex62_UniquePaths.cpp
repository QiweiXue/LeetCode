#include <utility.h>

using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
	vector<int> pathsColumn(m, 1);
	for (int i = 1; i < n; i++)
	  for (int j = 1; j < m; j++) {
		pathsColumn[j] = pathsColumn[j] + pathsColumn[j - 1];
	  }

	return pathsColumn[m - 1];
  }
};

int main() {
  auto res = Solution().uniquePaths(3, 2);
  std::cout << res;
  return 0;
}

