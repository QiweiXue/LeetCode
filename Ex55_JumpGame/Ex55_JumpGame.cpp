#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int size = nums.size();
        vector<bool> map(size, false);
        map[0] = true;
        for (int i = 0; i < size; i++) {
            if (map[i] == true) {
                for (int j = i; j < i + nums[i] + 1 && j < size; j++)
                    map[j] = true;
            }
        }
        return map[size - 1];
    }
};

int main() {
    vector<int> nums{2, 3, 1, 1, 4};
    auto res = Solution().canJump(nums);
    std::cout << res;
}
