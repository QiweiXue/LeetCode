#include <utility.h>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.empty())
			return false;
		if (nums.size() == 1 && nums[0] == target)
			return true;
		if (nums.size() == 1 && nums[0] != target)
			return false;

		int beg = 0;
		int end = nums.size() - 1;
		int mid;
		while (end > beg)
		{
			mid = (beg + end) / 2;
			if (nums[mid] == target || nums[beg] == target || nums[end] == target)
				return true;
			if (nums[mid] > nums[beg])
			{
				if (nums[beg] < target && target < nums[mid])
					end = mid - 1;
				else
					beg = mid + 1;
			}
			else if (nums[mid] < nums[beg])
			{
				if (nums[mid] < target && target < nums[end])
					beg = mid + 1;
				else
					end = mid - 1;
			}
			else
			{
				beg += 1;
			}
		}
		return false;
	}
};

int main(int argc, char* argv[])
{
	vector<int> nums{ 2,5,6,0,0,1,2 };
	int target = 0;
	auto res = Solution().search(nums, target);
	std::cout << res;
	return 0;
}
