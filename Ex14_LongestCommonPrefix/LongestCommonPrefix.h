#pragma once
#include <string>
#include <vector>

class LongestCommonPrefix
{
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) 
	{
		if (strs.empty() || strs[0].empty())
			return std::string();
		if (strs.size() == 1)
			return strs[0];
		std::string res;
		for (int i = 0; i< strs[0].size(); i++)
		{
			char c = strs[0].at(i);
			for (int j = 1; j < strs.size(); j++)
			{
				if ((strs[j].size() <= i) || (strs[j].at(i) != c))
					return res;
			}
			res.push_back(c);
		}
		return res;
	}
};

