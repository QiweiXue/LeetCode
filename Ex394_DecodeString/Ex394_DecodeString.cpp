#include <stack>
#include <string>

using namespace std;

class Solution {
public:
	string decodeString(string s) {
		stack<int> times;
		string res;
		bool isValid = true;
		int i = 0;
		while (i < s.size())
		{
			if (s[i] >= 'a' && s[i] <= 'z' || (s[i] >= 'A' && s[i] <= 'Z'))
				res.push_back(s[i++]);
			else if (s[i] >= '0' && s[i] <= '9')
			{
				int j = i;
				while (j < s.size() && (s[j] >= '0' && s[j] <= '9'))
					++j;
				if (j == s.size() || s[j] != '[')
				{
					isValid = false;
					break;
				}
				times.push(stoi(string(s.begin() + i, s.begin() + j)));
				res.push_back('[');
				i = j + 1;
			}
			else if (s[i] == ']')
			{
				++ i;
				int j = res.size() - 1;
				while (j >= 0 && res[j] != '[')
					--j;
				if (j == -1)
				{
					isValid = false;
					break;
				}
				string repeat(res.begin() + j + 1, res.end());
				res.erase(j, 1);

				int repeatTimes = times.top();
				times.pop();
				while (--repeatTimes > 0)
					res = res + repeat;
			}
			else
			{
				isValid = false;
				break;
			}
		}

		if(isValid == false)
			 return string();
		if (times.empty())
			return res;
	}
};

int main()
{
	auto res = Solution().decodeString("3[a]2[bc]");
	return 0;
}