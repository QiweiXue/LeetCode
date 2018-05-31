#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string getPermutation(int n, int k) {
	vector<int> f(n, 1);
	for (int i = 2; i < n; ++i)
	  f[i] = f[i - 1]*i;
	string s("123456789");
	string res;
	k--;
	for (int i = n; i > 0; i--) {
	  int j = k/f[i - 1];
	  k %= f[i - 1];
	  res.push_back(s[j]);
	  s.erase(j, 1);
	}
	return res;
  }
private:

};

int main() {
  auto res = Solution().getPermutation(3, 2);
  std::cout << res;
}