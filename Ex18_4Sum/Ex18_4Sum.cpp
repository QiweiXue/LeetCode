#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		std::sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		auto size = nums.size();
		if (size < 4)
			return result;

		std::unordered_map<int, vector<std::pair<int, int>> > map;

		for (int firstNo = 0; firstNo < size - 1; firstNo++)
			for (int secondNo = firstNo + 1; secondNo < size; secondNo++)
				map[nums[firstNo] + nums[secondNo]].push_back(std::make_pair(firstNo, secondNo));

		for (int thirdNo = 0; thirdNo < size - 1; thirdNo++)
			for (int forthNo = thirdNo + 1; forthNo < size; forthNo++)
			{
				auto fs = map.find(target - nums[thirdNo] - nums[forthNo]);
				if (fs == map.end())
					continue;

				for (auto& a : fs->second)
				{
					if (a.second >= thirdNo)
						continue;

					result.push_back({ nums[a.first], nums[a.second], nums[thirdNo], nums[forthNo] });
				}
			}
		std::sort(result.begin(), result.end());
		result.erase(std::unique(result.begin(), result.end()), result.end());
		return result;

	}
};

int main()
{
	std::vector<int> nums{ -3,-1,0,2,4,5};
	auto result = Solution().fourSum(nums, 0);

	for (auto & a : result)
	{
		for (auto &b : a)
			std::cout << b << " ";
		std::cout << std::endl;
	}
    return 0;
}

