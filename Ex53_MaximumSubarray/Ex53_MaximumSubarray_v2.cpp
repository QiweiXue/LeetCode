#include <vector>
#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        return max(nums, 0, nums.size());
    }

    int max(vector<int> &nums, int left, int right) {
        if (right - left == 1)
            return nums[left];

        int mid = (right + left) / 2;
        int leftmax = max(nums, left, mid);
        int rightmax = max(nums, mid, right);

        int leftsummax = INT32_MIN;
        int leftsum = 0;
        for (int i = mid - 1; i >= left; i--) {
            leftsum += nums[i];
            leftsummax = std::max(leftsummax, leftsum);
        }

        int rightsummax = INT32_MIN;
        int rightSum = 0;
        for (int i = mid; i < right; i++) {
            rightSum += nums[i];
            rightsummax = std::max(rightSum, rightsummax);
        }

        return std::max(rightsummax + leftsummax, std::max(leftmax, rightmax));
    }
};

int main() {
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int res = Solution().maxSubArray(nums);
    std::cout << res;
    return 0;
}
