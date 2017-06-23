#pragma once
#include <vector>
#include <algorithm>

class ContainerWithMostWater
{
public:
	int maxArea(std::vector<int>& height) {
		int left = 0;
		int right = height.size() -1 ;
		int area = right * std::min(height[0], height[right]);
		while (left < right)
		{
			area = std::max(area, std::min(height[left], height[right]) *(right-left));
			if (height[left] < height[right])
				left++;
			else
				right--;
		}
		return area;
	}
};

