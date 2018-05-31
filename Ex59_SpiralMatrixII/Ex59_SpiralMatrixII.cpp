#include <vector>
#include <iostream>

using namespace std;

void printMatrix(vector<vector<int>> &mat) {
	for (auto &a : mat) {
		for (auto &b : a)
			std::cout << b << " ";
		std::cout << std::endl;
	}
}

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		int row = n;
		int column = n;
		int right = column;
		int down = row - 1;
		int left = column - 1;
		int up = row - 2;
		int num = 1;
		direction dir = direction::right;
		int i = 0, j = 0;
		while (right > 0 || down > 0 || left > 0 || up > 0) {
			switch (dir) {
				case direction::right:
					for (int k = 0; k < right; k++)
						//res.push_back(matrix[i][j++]);
						res[i][j++] = num++;
					j--;
					i++;
					right -= 2;
					dir = direction::down;
					break;
				case direction::down:
					for (int k = 0; k < down; k++)
						//res.push_back(matrix[i++][j]);
						res[i++][j] = num++;
					i--;
					j--;
					down -= 2;
					dir = direction::left;
					break;
				case direction::left:
					for (int k = 0; k < left; k++)
						//res.push_back(matrix[i][j--]);
						res[i][j--] = num++;
					left -= 2;
					i--;
					j++;
					dir = direction::up;
					break;
				case direction::up:
					for (int k = 0; k < up; k++)
						//res.push_back(matrix[i--][j]);
						res[i--][j] = num++;
					up -= 2;
					i++;
					j++;
					dir = direction::right;
					break;
			}
		}
		return res;
	}

private:
	enum class direction {
		right,
		down,
		left,
		up
	};
};


int main() {
	auto res = Solution().generateMatrix(5);
	printMatrix(res);
	auto res2 = Solution().generateMatrix(6);
	printMatrix(res2);
}