#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string countAndSay(int n)
	{
		vector<string> store;
		store.push_back("1");
		store.push_back("1");
		store.push_back("11");
		for (int i = 3; i < n + 1; i++)
		{
			store.push_back("");
			string & nowString = store[i];
			int beg = 0;
			for (int j = 1; j < store[i - 1].size(); j++)
			{
				if (store[i - 1][j] == store[i - 1][beg])
					continue;
				else
				{
					int count = j - beg;
					char say = store[i - 1][beg];
					nowString = nowString + std::to_string(count) + std::to_string(say - '0');
					beg = j;
				}
			}

			int lastCount = store[i - 1].size() - beg;
			char lastSay = store[i - 1][beg];
			nowString = nowString + std::to_string(lastCount) + std::to_string(lastSay - '0');
		}
		return store[n];
	}
};


int main()
{
	auto res = Solution().countAndSay(5);
    return 0;
}

