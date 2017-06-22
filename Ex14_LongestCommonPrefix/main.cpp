#include "LongestCommonPrefix.h"
#include <iostream>

int main()
{
	const char* s[] = { "c", "c"};
	std::vector<std::string> v(s, s + 2);
	std::cout << LongestCommonPrefix().longestCommonPrefix(v) << std::endl;
	system("pause");
}
