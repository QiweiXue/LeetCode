#include "LongestPalindromicSubstring.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::string LongestPalindromicSubstring::longestPalindrome(std::string s)
{
	if (s.empty())
		return s;
	string newString(s);
	for(int i = 0; i < s.size(); i ++)
	{
		newString.insert(2 * i, "#");
	}
	newString.push_back('#');
#ifdef _DEBUG	
	cout << "newString : " << newString << endl;
#endif

	vector<int> radiusLength(newString.size(), 1);
	int nowPos = 1;
	int maxRightPos = 0;
	int maxRightRadius = 1;

	while(nowPos < newString.size())
	{
		int nowRadius;
		if(nowPos < maxRightPos + maxRightRadius)
		{
			nowRadius = min(maxRightPos + maxRightRadius - 1 - nowPos, radiusLength[2 * maxRightPos - nowPos]);
		}
		else
		{
			nowRadius = 1;
		}

		while ((nowPos - nowRadius >= 0) 
			&& (nowPos + nowRadius < newString.size()))
		{
			if(newString[nowPos - nowRadius] == newString[nowPos + nowRadius])
				nowRadius++;
			else
				break;
		}

		radiusLength[nowPos] = nowRadius;
		if(nowPos + nowRadius > maxRightPos + maxRightRadius)
		{
			maxRightPos = nowPos;
			maxRightRadius = nowRadius;
		}
		++nowPos;
	}

	auto index = max_element(radiusLength.begin(), radiusLength.end());
	auto radius = *index;

	string res;
	for(auto i = index-radiusLength.begin() - radius + 1; i < index-radiusLength.begin() + radius; i ++)
	{
		if (newString[i] != '#')
			res.push_back(newString[i]);
	}
	
	return res;
}
