#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int maxSum = INT32_MIN;
		//int max = nums[0];
		int localSum = INT32_MIN;
		for(int i = 0; i < nums.size(); i ++)
		{
			if (localSum <= 0)
				localSum = nums[i];
			else
				localSum += nums[i];
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

