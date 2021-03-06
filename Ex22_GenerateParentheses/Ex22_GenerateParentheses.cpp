#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	void DFS(int left, int right, string out, vector<string>& res)
	{
		if (left < 0 || right < 0 || left > right)
			return;
		if (left == 0 && right == 0)
			res.push_back(out);
		else
		{
			DFS(left - 1, right, out + "(", res);
			DFS(left, right - 1, out + ")", res);
		}
	}

	vector<string> generateParenthesis(int n)
	{
		vector<string> result;
		if (n <= 0) 
			return result;
		DFS(n, n, "", result);
		return result;
	}
};

int main()
{
	auto res = Solution().generateParenthesis(2);
	for (auto & a : res)
	{
		std::cout << a << "\n";
	}
    return 0;
}

