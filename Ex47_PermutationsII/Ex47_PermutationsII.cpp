#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		vector<vector<int>> res;
		if (nums.empty())
			return res;
		//std::sort(nums.begin(), nums.end());
		dfs(nums, res, 0);
		return res;
	}

	void dfs(vector<int>& nums, vector<vector<int>>& res, int beg)
	{
		if (beg == nums.size() - 1)
			res.push_back(nums);
		else
		{
			unordered_set<int> set;
			//set.emplace(nums[beg]);
			//dfs(nums, res, beg + 1);
			for (int i = beg ; i < nums.size(); i++)
			{
				auto find = set.find(nums[i]);
				if( find == set.end())
				{				
					set.emplace(nums[i]);
					using std::swap;
					swap(nums[beg], nums[i]);				
					dfs(nums, res, beg + 1 );					
					swap(nums[beg], nums[i]);
				}
			}
		}
	}
};

int main()
{
	vector<int> nums{ 2,2,1,1};
	auto res = Solution().permuteUnique(nums);
	return 0;
}

