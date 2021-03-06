#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		vector<vector<string>> res;
		int index = 0;
		unordered_map<string, int> map;
		for (auto& a : strs)
		{
			string acopy = a;
			std::sort(acopy.begin(), acopy.end());
			auto find = map.find(acopy);
			if (find == map.end())
			{
				map.emplace(acopy, index++);
				res.push_back( vector<string>{a} );
			}
			else
			{
				int i = find->second;
				res[i].push_back(a);
			}
		}
		return res;
	}
};

void printRes(vector<vector<string>> strs)
{
	for (auto & a : strs)
	{
		for (auto & b : a)
			std::cout << b << " ";
		std::cout << std::endl;
	}
}

int main()
{
	vector<string> strs{ "eat", "tea", "tan", "ate", "nat", "bat" };
	auto res = Solution().groupAnagrams(strs);
	printRes(res);
    return 0;
}

