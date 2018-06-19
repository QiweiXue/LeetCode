#include <utility.h>

using namespace std;

class Solution
{
public:
	vector<int> grayCode(int n) {
		if (n == 0)
			return { 0 };
		if (n == 1)
			return { 0, 1 };
		vector<int> pre = grayCode(n - 1);
		int size = pre.size();
		for(int i = 0; i < size; i ++)
		{
			pre.push_back(pow( 2, n - 1 ) + pre[size - 1 - i]);
		}
		return pre;
	}
};

int main()
{
	auto res = Solution().grayCode(2);
	printDigits(res);
	return 0;
}