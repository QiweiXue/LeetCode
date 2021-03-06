#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return 1;
		int pre = 0;
		int back = 1;
		while (back < nums.size())
		{
			while (nums[back] == nums[pre])
			{
				back++;
				if (back == nums.size())
					break;
			}
			if (back != nums.size())
				nums[pre + 1] = nums[back];
			pre++;
		}
		return pre;
	}
};
int main()
{
	vector<int> nums{ 0,0,1,1,1,2,2,3,3,4 };
	auto total = Solution().removeDuplicates(nums);

	std::cout << "total : " << total << std::endl;
	for (int i = 0; i < total; i++)
		std::cout << nums[i] << " ";
    return 0;
}

