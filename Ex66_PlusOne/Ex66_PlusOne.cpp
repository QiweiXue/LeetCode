#include <utility.h>
using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int> &digits) {
	auto res = digits;
	auto i = res.rbegin();
	while (i < res.rend()) {
	  if (*i!=9) {
		(*i)++;
		break;
	  } else {
		*i = 0;
		i++;
	  }
	}
	if (i==res.rend())
	  res.insert(res.begin(), 1);
	return res;
  }
};

int main() {
  vector<int> digits{1, 2, 3, 9, 9};
  auto res = Solution().plusOne(digits);
  printDigits(res);
  return 0;
}
