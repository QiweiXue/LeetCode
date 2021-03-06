#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	void buildNext(const string& needle)
	{
		nextTable.clear();
		nextTable.resize(needle.size());
		nextTable[0] = - 1;
		int index = 0;
		int patternIndex = -1;
		while (index < needle.size() - 1)
		{
			while (!(patternIndex < 0 || needle[index] == needle[patternIndex]))
			{
				patternIndex = nextTable[patternIndex];
			}
			nextTable[++index] = ++patternIndex;
		}
	}

	int strStr(string haystack, string needle) 
	{
		if (needle.empty())
			return 0;
		if (haystack.empty())
			return -1;
		int strIndex = 0;
		int patternIndex = 0;
		buildNext(needle);
		while (strIndex < haystack.size())
		{
			if (patternIndex < 0 || haystack[strIndex] == needle[patternIndex])
			{
				++strIndex;
				++patternIndex;
				if (patternIndex == needle.size())
					return strIndex - needle.size();
			}
			else
			{
				patternIndex = nextTable[patternIndex];
			}
		}
		return -1;
	}

private:
	vector<int> nextTable;
};


int main()
{
	auto res = Solution().strStr("hello", "ll");
    return 0;
}

