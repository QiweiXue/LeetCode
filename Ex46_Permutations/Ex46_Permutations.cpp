#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<vector<int>> res;
		if (nums.empty())
			return res;
		dfs(nums, res, 0);
		return res;
	}

	void dfs(vector<int>& nums, vector<vector<int>>& res, int beg)
	{
		if (beg == nums.size() - 1)
			res.push_back(nums);
		else
		{
			dfs(nums, res, beg + 1);
			for (int i = beg + 1; i < nums.size(); i++)
			{
				using std::swap;
				swap(nums[beg], nums[i]);
				dfs(nums, res, beg + 1);
				swap(nums[beg], nums[i]);
			}
		}
	}
};
int main()
{
	vector<int> nums{ 1,2,3 };
	auto res = Solution().permute(nums);
    return 0;
}

