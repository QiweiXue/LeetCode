# include "Solution.h"
#include <vector>
#include <iostream>

int main (int argc, char** argv)
{
	std::vector<std::string> strings{"cvv","dvdf","hhhh","abcabcb","pwwkew"};
	for(auto& a: strings)
	{
		std::cout << a << ": " << Solution().lengthOfLongestSubstring(a) << std::endl;
	}
	system("pause");
}