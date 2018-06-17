#include <utility.h>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int i = 0;
		int j = 0;
		int dupTimes = 0;
		int pre = nums[0] + 1;
		for(; j < nums.size(); j ++)
		{
			if(nums[j] == pre)
			{
				dupTimes++;
				if(dupTimes < 2)
					nums[i++] = nums[j];
			}
			else
			{
				dupTimes = 0;
				nums[i++] = nums[j];
			}
			pre = nums[j];
		}
		return i;
	}
};

int main()
{
	vector<int> nums{ 0,0,1,1,1,1,2,3,3 };
	auto res = Solution().removeDuplicates(nums);
	std::cout << res;
	return 0;
}