#include <string>
using namespace std;

class Solution
{
public:
	string multiply(string num1, string num2)
	{
		if (num1 == "0" || num2 == "0")
		{
			return "0";
		}
		int len1 = num1.size();
		int len2 = num2.size();
		string res;
		res.reserve(len1 + len2 - 1);
		int remain = 0;
		for (int i = 0; i < len1 + len2 ; i++)
		{
			int sum = 0;
			for (int j = 0; j < i + 1; j++)
			{
				int pos1 = len1 - 1 - j;
				int pos2 = len2 - (i - j) - 1;
				if(pos1 >= 0 && pos1 < len1 && pos2 >=0 && pos2< len2)
				sum += oncesPlace(char2digit(num1[pos1]) * char2digit(num2[pos2]));
			}

			for (int k = 0; k < i ; k++)
			{
				int pos1 = len1 - 1 - k;
				int pos2 = len2 - 1 - (i - k - 1);
				if (pos1 >= 0 && pos1 < len1 && pos2 >= 0 && pos2< len2)
				sum += tensPlace(char2digit(num1[pos1]) * char2digit(num2[pos2]));
			}
			sum += remain;		
			res.push_back(digit2char(oncesPlace(sum)));
			remain = tensPlace(sum);
		}
		if (remain != 0)
		{
			string remainStr = std::to_string(remain);
			std::reverse(remainStr.begin(), remainStr.end());
			res += remainStr;
		}
		std::reverse(res.begin(), res.end());
		if (res[0] == '0')
			return string(res.begin() + 1, res.end());
		else
			return res;
	}

private:
	inline int char2digit(char c)
	{
		return c - '0';
	}

	inline char digit2char(int i)
	{
		return '0' + i;
	}

	inline int oncesPlace(int i)
	{
		return i % 10;
	}

	inline int tensPlace(int i)
	{
		return i / 10;
	}
};

int main()
{
	auto res = Solution().multiply("123", "456");
    return 0;
}

