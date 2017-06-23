#include"ContainerWithMostWater.h"
#include <iostream>

using namespace std;

int main(int argc, char ** argv)
{
	vector<int> height{ 4,6,2,6,7,11,2 };
	std::cout << ContainerWithMostWater().maxArea(height);
	system("pause");
	return 0;
}
