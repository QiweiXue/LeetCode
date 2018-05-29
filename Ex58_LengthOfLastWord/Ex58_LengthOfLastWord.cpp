#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

class Solution 
{
public:
	int lengthOfLastWord(string s) {
		auto notempty = std::find_if_not(std::rbegin(s), std::rend(s), 
			[](char c){ return c == ' ';
			});
		auto res = std::find(notempty, std::rend(s), ' ');
		return res - notempty;
	}
};

int main()
{
	std::cout << Solution().lengthOfLastWord("Hegggggllo World ");
	return 0;
}