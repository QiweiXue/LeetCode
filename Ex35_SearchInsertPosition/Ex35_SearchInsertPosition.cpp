#include <vector>

using namespace std;

class Solution
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		size_t size = nums.size();
		if (size == 0)
			return 0;
		if (size == 1)
			return target <= nums[0] ? 0 : 1;
		int beg = 0;
		int end = size;
		while (end - beg > 1)
		{
			int mid = (beg + end) / 2;
			if (nums[mid] <= target)
				beg = mid;
			else
				end = mid;
		}
		return target<= nums[beg] ? beg : end;
	}
};


int main()
{
	vector<int> nums{ 1 };
	auto res = Solution().searchInsert(nums, 2);
    return 0;
}

