#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) 
	{
		size_t size = nums.size();
		if (size == 0 || (size == 1 && nums[0] != target))
			return -1;
		if (size == 1 && nums[0] == target)
			return 0;
		size_t beg = 0, end = size - 1;
		while (end > beg )
		{
			size_t mid = (beg + end) / 2;
			if (nums[beg] == target)
				return beg;
			if (nums[end] == target)
				return end;
			if (nums[mid] == target)
				return mid;
			if (end - beg == 1)
				break;

			if (nums[beg] < nums[mid])
			{
				if (nums[beg] < target && target < nums[mid])
				{
					end = mid;
				}
				else
				{
					beg = mid;
				}
			}
			else
			{
				if (nums[mid] < target && target < nums[end])
				{
					beg = mid;
				}
				else
				{
					end = mid;
				}
			}
			continue;
		}
		return -1;
	}
};

int main()
{
	vector<int> nums{ 4,5,6,7,8,1,2,3 };
	auto res = Solution().search(nums, 8);
    return 0;
}
