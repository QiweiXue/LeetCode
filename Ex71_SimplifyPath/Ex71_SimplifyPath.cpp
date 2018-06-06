#include <utility.h>
#include <deque>

using namespace std;

class Solution {
 public:
  string simplifyPath(string path) {
	vector<string> res;
	int start = 0;
	int end;
	std::pair<int, int> range;
	while (true) {
	  auto range = findNextName(path, start);
	  if (range.first==-1)
		break;
	  else {
		string name = string(path, range.first, range.second - range.first);

		if (!res.empty() && name=="..")
		  res.pop_back();

		else if (name!="." && name!="..")
		  res.push_back(name);
		start = range.second;
	  }
	}

	string resStr;
	for (auto &a: res) {
	  resStr = resStr + "/" + a;
	}
	//resStr += "/";
	if (res.empty())
	  return "/";
	return resStr;
  }

  inline std::pair<int, int> findNextName(string &s, int start) {
	int beg = s.find_first_of('/', start);
	if (beg==string::npos)
	  return {-1, -1};
	while (beg < s.size() - 1 && s[beg + 1]=='/')
	  beg = beg + 1;
	if (beg==s.size() - 1)
	  return {-1, -1};

	int end = s.find_first_of('/', beg + 1);
	if (end==string::npos)
	  return {beg + 1, s.size()};

	return {beg + 1, end};
  }
};

int main() {
  string res = Solution().simplifyPath("/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///");
  std::cout << res;
}
