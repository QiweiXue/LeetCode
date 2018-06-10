#include <utility.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> res;
	vector<int> temp;
	dfs(1, n, k, res, temp);
	return res;
  }

  void dfs(int now, int n, int k, vector<vector<int>> &res, vector<int> &temp) {
	if (k==0)
	  res.push_back(temp);
	for (int i = now; i <= n; i++) {
	  temp.push_back(i);
	  dfs(i + 1, n, k - 1, res, temp);
	  temp.pop_back();
	}
  }
};

int main() {
  auto res = Solution().combine(4, 2);
  printMatrix(res);
  return 0;
}

