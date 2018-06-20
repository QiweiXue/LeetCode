#include <utility.h>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		int size = s.size();
		if (size == 1)
		{
			if (s == "0")
				return 0;
			else
				return 1;
		}
		if (size == 2)
			return twoNum(s);

		vector<int> v(size, 0);
		if (s[0] != '0')
			v[0] = 1;
		else
			return 0;

		v[1] = twoNum(string(s.begin(), s.begin() + 2));
		if (v[1] == 0)
			return 0;

		for(int i = 2; i < size ; i++)
		{
			if(s[i] == '0')
			{
				if (s[i - 1] == '1' || s[i - 1] == '2')
					v[i] = v[i - 2];
				else
					return 0;
			}
			else
			{
				int j, k;
				j = v[i - 1];
				
				int two = std::stoi(string(s.begin() + i - 1, s.begin() + i + 1));
				if (two > 10 && two <=26)
					k = v[i - 2] ;
				else
					k = 0;
				v[i] = j + k;
			}
		}
		return v[size - 1];
	}

	int twoNum(const string& s)
	{
		int i = std::stoi(s);
		if (i < 10) // s[0] == 0
			return 0;
		if (i == 10 || i == 20)
			return 1;
		if (i > 10 && i <= 26)
			return 2;
		if (i > 26 && s[1] != '0')
			return 1;
		else
			return 0;
	}
};

int main()
{
	auto res = Solution().numDecodings("233");
	std::cout << res;
	return 0;
}