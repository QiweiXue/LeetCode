#include <utility.h>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> nums1bak{ nums1.begin(), nums1.begin() + m };

		int n1 = 0, n2 = 0;
		int val;
		for(int i = 0; i < m + n;i ++)
		{
			if ((n1 < m && n2 < n && nums1bak[n1] <= nums2[n2]) || (n2 == n))
				val = nums1bak[n1++];
			else
				val = nums2[n2++];

			if (i < nums1.size())
				nums1[i] = val;
			else
				nums1.push_back(val);
		}
	}
};

int main()
{
	vector<int> nums1{ 1,2,3,0,0,0 };
	vector<int> nums2{ 2,5,6 };
	Solution().merge(nums1, 3, nums2, 3);
	printDigits(nums1);
	return 0;
}