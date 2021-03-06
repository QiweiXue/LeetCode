#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
	vector<string> letterCombinations(string digits) 
	{
		vector<string> digitLetter{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

		vector<int> digitsNo;
		for (auto &a : digits)
		{
			digitsNo.push_back(a - '0');
		}
		vector<string> result;
		if (digits.empty())
			return result;
		vector<int> index( digits.size() + 1, 0);
		int pos = 0;
		while (index[digits.size()] == 0)
		{
			string str;
			for (int i = 0 ; i < digitsNo.size(); i ++)
			{
				str.push_back(digitLetter[digitsNo[i]].at(
					index[i]));
			}
			result.push_back(str);

			index[pos]++;

			bool flag = false;
			while (index[digits.size()] == 0  
				&& index[pos] == digitLetter[digitsNo[pos]].size())
			{
				flag = true;
				index[pos] = 0;
				pos++;
				index[pos]++;
			} 
			if (flag)
				pos = 0;
		}

		return result;
	}
	
};

int main()
{
	auto res = Solution().letterCombinations("");
	for (auto& a : res)
	{
		std::cout << a << " ";
	}
	std::cout << std::endl;
    return 0;
}

