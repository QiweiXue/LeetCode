#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	void nextPermutation(vector<int>& nums)
	{
		size_t size = nums.size();
		if (size < 2)
			return;
		size_t changePos = size - 1;
		while (changePos > 0)
		{
			if (nums[changePos] > nums[changePos - 1])
				break;
			changePos--;
		}
		if (changePos == 0)
		{
			std::sort(nums.begin(), nums.end());
			return;
		}

		int beforeChangePosValue = nums[changePos - 1];
		size_t pos = size - 1;
		while (nums[pos] <= beforeChangePosValue)
		{
			pos--;
		}

		using std::swap;
		swap(nums[changePos - 1], nums[pos]);
		std::sort(nums.begin() + changePos, nums.end());
	}
};
int main()
{
	vector<int> nums{ 2,4,3,1 };
	Solution().nextPermutation(nums);
    return 0;
}

