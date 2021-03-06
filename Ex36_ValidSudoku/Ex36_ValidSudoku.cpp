#include <vector>
#include <unordered_set>
#include <array>

using namespace std;

class Solution
{
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		array<unordered_set<int>, 9> rowSet;
		array<unordered_set<int>, 9> columnSet;
		array<unordered_set<int>, 9> gridSet;
		for(int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
					continue;

				if (rowSet[i].find(board[i][j]) != rowSet[i].end())
					return false;
				else
					rowSet[i].emplace(board[i][j]);

				if (columnSet[j].find(board[i][j]) != columnSet[j].end())
					return false;
				else
					columnSet[j].emplace(board[i][j]);
				
				if (gridSet[int(i / 3) *3 + int(j / 3)].find(board[i][j]) != gridSet[int(i / 3)*3 + int(j / 3)].end())
					return false;
				else
					gridSet[int(i / 3) *3+ int(j / 3)].emplace(board[i][j]);
			}

		return true;
	}
};


int main()
{
	vector<vector<char>> board = {
	{ '3', '3', '.', '.', '7', '.', '.', '.', '.' },
	{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
	{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
	{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
	{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
	{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
	{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
	{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
	{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	};
	bool res = Solution().isValidSudoku(board);
    return 0;
}

