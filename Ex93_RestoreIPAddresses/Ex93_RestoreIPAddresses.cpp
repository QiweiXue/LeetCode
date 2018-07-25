#include <utility.h>

using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {

	}
};

int main(int argc, char* argv[])
{
	string s("25525511135");
	auto res = Solution().restoreIpAddresses(s);
	printDigits(res);
	return 0;
}
