#include <utility.h>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int> &nums) {
	int totalSize = nums.size();
	int redIndex = 0;
	int blueIndex = totalSize;
	int i = 0;
	while (i < blueIndex) {
	  using std::swap;
	  if (nums[i]==0) {
		swap(nums[redIndex], nums[i]);
		i++;
		redIndex++;
	  } else if (nums[i]==1) {
		i++;
	  } else {
		blueIndex--;
		swap(nums[i], nums[blueIndex]);
	  }
	}
  }
};

int main() {
  vector<int> nums{1, 0, 2, 1, 1, 0};
  Solution().sortColors(nums);
  printDigits(nums);
  return 0;
}
