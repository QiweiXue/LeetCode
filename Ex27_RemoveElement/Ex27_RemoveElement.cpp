#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty())
			return 0;
		int pre = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
			{
				nums[pre] = nums[i];
				pre++;
			}
		}
		return pre;
	}
};

int main()
{
	vector<int> nums{ 0,1,2,2,3,0,4,2 };
	auto total = Solution().removeElement(nums, 2);

	std::cout << "total : " << total << std::endl;
	for (int i = 0; i < total; i++)
		std::cout << nums[i] << " ";
	return 0;
}

