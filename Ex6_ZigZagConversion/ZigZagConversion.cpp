#include "ZigZagConversion.h"
#include <vector>

using namespace std;

std::string ZigZagConversion::convert(std::string s, int numRows)
{
	if (numRows == 1 || numRows == 0)
		return s;
	vector<string> strings(numRows);
	int loopNumber = 2 * numRows - 2;
	int index = 0;
	while(index < s.size())
	{
		int remain = index % loopNumber;
		if (remain < numRows)
			strings[remain].push_back(s[index]);
		else
			strings[loopNumber - remain].push_back(s[index]);
		index++;
	}

	string res;
	for (auto& a : strings)
		res += a;
	return res;
}
