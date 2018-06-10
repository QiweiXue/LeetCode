#include <utility.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int> &nums) {
	vector<vector<int>> res;
	vector<int> temp;
	dfs(0, nums.size(), res, temp, nums);
	return res;
  }

  void dfs(int now, int k, vector<vector<int>> &res, vector<int> &temp, vector<int> &input) {
	res.push_back(temp);
	for (int i = now; i < input.size(); i++) {
	  temp.push_back(input[i]);
	  dfs(i + 1, k - 1, res, temp, input);
	  temp.pop_back();
	}
  }
};

int main() {
  vector<int> nums{1, 2, 3};
  auto res = Solution().subsets(nums);
  printMatrix(res);
}
