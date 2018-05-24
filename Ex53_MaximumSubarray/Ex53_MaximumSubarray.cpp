#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int maxSum = nums[0];
		int max = nums[0];
		int localSum = 0;
		for(int i = 0; i < nums.size(); i ++)
		{
			max = std::max(max, nums[i]);
			localSum += nums[i];
			if (localSum <= 0)
				localSum = 0;
			else
				maxSum = std::max(localSum, maxSum);
		}
		return maxSum;
	}
};

int main()
{
	vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };
	int res = Solution().maxSubArray(nums);
    return 0;
}

