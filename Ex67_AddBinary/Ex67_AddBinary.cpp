#include <utility.h>

using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
	auto ai = a.rbegin();
	auto bi = b.rbegin();
	string res;
	int remain = 0;
	while (ai < a.rend() || bi < b.rend() || remain > 0) {
	  int abit = 0, bbit = 0;
	  if (ai < a.rend()) {
		abit = *ai - '0';
		ai++;
	  }
	  if (bi < b.rend()) {
		bbit = *bi - '0';
		bi++;
	  }
	  int sum = abit + bbit + remain;
	  switch (sum) {
		case 0:res.push_back('0');
		  remain = 0;
		  break;
		case 1:res.push_back('1');
		  remain = 0;
		  break;
		case 2:res.push_back('0');
		  remain = 1;
		  break;
		case 3:res.push_back('1');
		  remain = 1;
		  break;
	  }
	}
	std::reverse(res.begin(), res.end());
	return res;
  }
};

int main() {
  string res = Solution().addBinary("1111", "1111");
  std::cout << res;
  return 0;
}
