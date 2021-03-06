#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	void rotate(vector<vector<int>>& matrix)
	{
		int rank = matrix.size();
		for (int i = 0; i < rank / 2 ; i++)
		{
			for (int j = 0; j < rank / 2 ; j++)
			{
				int& num0 = matrix[i][j];
				int& num1 = matrix[j][rank - 1 - i];
				int& num2 = matrix[rank - 1 - i][rank - 1 - j];
				int& num3 = matrix[rank - 1 - j][i];
				using std::swap;
				swap(num0, num3);
				swap(num1, num2);
				swap(num1, num3);
			}
		}
		if (rank % 2 == 1)
		{
			int j = rank / 2;
			for (int i = 0; i < rank / 2 ;i ++)
			{
				int& num0 = matrix[i][j];
				int& num1 = matrix[j][rank - 1 - i];
				int& num2 = matrix[rank - 1 - i][rank - 1 - j];
				int& num3 = matrix[rank - 1 - j][i];
				using std::swap;
				swap(num0, num3);
				swap(num1, num2);
				swap(num1, num3);
			}
		}
	}
}; 

void printMatrix(vector<vector<int>>& mat)
{
	for (auto & a : mat)
	{
		for (auto & b : a)
			std::cout << b << " ";
		std::cout << std::endl;
	}
}

int main()
{
	vector<vector<int>> matrix{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	//vector<vector<int>> matrix{
	//	{ 1,2,3,4 },
	//	{ 5,6,7,8 },
	//	{ 9,10,11,12},
	//	{13,14,15,16}
	//};
	std::cout << "before rotate: \n";
	printMatrix(matrix);

	Solution().rotate(matrix);

	std::cout << "after rotate: \n";
	printMatrix(matrix);
    return 0;
}

