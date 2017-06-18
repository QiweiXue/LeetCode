#include "Solution.h"
#include <unordered_set>

using namespace std;

Solution::Solution()
{
}


Solution::~Solution()
{
}

int Solution::lengthOfLongestSubstring(std::string s)
{
	if (s.empty())
		return 0;
	int length = 1;
	int p0 = 0;
	int p1 = 0;
	int size = s.size();
	vector<char> charSet;
	while(p1 != size)
	{
		auto res = std::find(charSet.begin(), charSet.end(), s[p1]);
		if (res == charSet.end())
		{
			charSet.push_back(s[p1]);
			++p1;
		}
		else
		{			
			length = length > charSet.size() ? length : charSet.size();
			p0 = res - charSet.begin() + p0 + 1;
			++p1;
			charSet = vector<char>(&s[p0], &s[p1]);
			
		}
	}
	return length > charSet.size() ? length : charSet.size();
}

