#include <utility.h>

using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
	if (n==1)
	  return 1;
	if (n==2)
	  return 2;
	int prepre = 1;
	int pre = 2;
	int now;
	while (n-- > 2) {
	  now = prepre + pre;
	  prepre = pre;
	  pre = now;
	}
	return now;
  }
};

int main() {
  int res = Solution().climbStairs(7);
  std::cout << res;
  return res;
}

