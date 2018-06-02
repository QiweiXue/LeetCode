#include <utility.h>
#include <cmath>
class Solution {
 public:
  int mySqrt(int x) {
	if (x==0)
	  return 0;
	double res = 1;
	while (std::abs(res*res - x) > 0.1) {
	  res = res - (res*res - x)/(2*res);
	}
	res = std::abs(res);
	return res;
  }
};

int main() {
  int res = Solution().mySqrt(2147395599);
  std::cout << res;
}
