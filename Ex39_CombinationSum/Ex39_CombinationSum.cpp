#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		std::sort(candidates.begin(), candidates.end());
		vector<vector<int>> res;
		if (candidates.empty())
			return res;
		if (candidates[0] > target)
			return res;
		vector<int> current;
		dfs(candidates, res, current, target, 0);
		return res;
	}

	void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& current, int target, int beg)
	{

		if (target == 0)
		{
			res.push_back(current);
			return;
		}
		for (int i = beg; i < candidates.size(); i++)
		{
			int newTarget = target - candidates[i];
			if (target < 0)
			{
				return;
			}
			current.push_back(candidates[i]);
			dfs(candidates, res, current, newTarget, i);
			current.pop_back();
		}
	}
};

int main()
{
	vector<int> candidates{ 2,3,5 };
	auto res = Solution().combinationSum(candidates, 8);
    return 0;
}

