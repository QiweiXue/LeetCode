#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		size_t size = nums.size();
		if (size == 0)
			return { -1, -1 };
		if (size == 1 && nums[0] == target)
			return { 0, 0 };
		if (size == 1 && nums[0] != target)
			return { -1, -1 };

		vector<int> res{ -1,-1 };
		int beg = 0, end = size - 1;
		int mid;
		while (end - beg > 1)
		{
			mid = (end + beg) / 2;
			if (nums[mid] == target)
			{
				res[0] = searchStart(nums, beg, mid, target);
				res[1] = searchEnd(nums, mid, end, target);
				return res;
			}
			else if (nums[mid] < target)
				beg = mid;
			else
				end = mid;
		}

		if (nums[beg] == target && nums[end] == target)
			return { beg, end };
		if (nums[beg] == target && nums[end] != target)
			return { beg, beg };
		if (nums[beg] != target && nums[end] == target)
			return { end, end };
		if (nums[beg] != target && nums[end] != target)
			return { -1, -1 };
	}

private:
	int searchStart(vector<int>& nums, int beg, int end, int target)
	{
		if (beg == end)
			return beg;
		if (beg == end - 1 && nums[beg] == target)
			return beg;
		if (beg == end - 1 && nums[beg] != target)
			return end;

		int mid;
		while (end - beg > 1)
		{
			mid = (beg + end) / 2;
			if (nums[mid] == target)
				end = mid;
			else if (nums[mid] < target)
				beg = mid;
		}
		return nums[beg] == target ? beg : end;
	}

	int searchEnd(vector<int>& nums, int beg, int end, int target)
	{
		if (beg == end)
			return beg;
		if (beg == end - 1 && nums[end] == target)
			return end;
		if (beg == end - 1 && nums[end] != target)
			return beg;

		int mid;
		while (end - beg > 1)
		{
			mid = (beg + end) / 2;
			if (nums[mid] == target)
				beg = mid;
			else if (nums[mid] > target)
				end = mid;
		}
		return nums[end] == target ? end : beg;
	}
};

int main()
{
	vector<int> nums{1,2,3};
	auto res = Solution().searchRange(nums, 1);
    return 0;
}

