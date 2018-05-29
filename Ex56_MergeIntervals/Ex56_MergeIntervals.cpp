#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) 
	{
		vector<Interval> res;
		if (intervals.empty())
			return res;
		if (intervals.size() == 1)
			return intervals;	
		std::sort(intervals.begin(), intervals.end(), 
			[](const Interval& a, const Interval& b) -> bool
			{
				return a.start < b.start;
			});
		res.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); i++)
		{
			if (res.back().end < intervals[i].start)
				res.push_back(intervals[i]);
			else
			{
				res.back().end = std::max(res.back().end, intervals[i].end);
			}
		}
		return res;
	}
};

void printIntervals(vector<Interval>& v)
{
	for (auto &a : v)
	{
		std::cout << a.start << " " << a.end << "\n";
	}
}
int main()
{
	vector<Interval> intervals{ Interval(1,3),
		Interval(2,6),
		Interval(8,10),
		Interval(15,18) };
	auto res = Solution().merge(intervals);
	printIntervals(res);
	return 0;
}