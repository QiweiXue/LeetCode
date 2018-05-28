#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
        int row = matrix.size();
        int coloum = matrix[0].size();
        int right = coloum;
        int down = row - 1;
        int left = coloum - 1;
        int up = row - 2;
        direction dir = direction::right;
        int i = 0, j = 0;
        while (right > 0 || down > 0 || left > 0 || up > 0) {
            switch (dir) {
                case direction::right:
                    for (int k = 0; k < right; k++)
                        res.push_back(matrix[i][j++]);
                    j--;
                    i++;
                    right -= 2;
                    dir = direction::down;
                    break;
                case direction::down:
                    for (int k = 0; k < down; k++)
                        res.push_back(matrix[i++][j]);
                    i--;
                    j--;
                    down -= 2;
                    dir = direction::left;
                    break;
                case direction::left:
                    for (int k = 0; k < left; k++)
                        res.push_back(matrix[i][j--]);
                    left -= 2;
                    i--;
                    j++;
                    dir = direction::up;
                    break;
                case direction::up:
                    for (int k = 0; k < up; k++)
                        res.push_back(matrix[i--][j]);
                    up -= 2;
                    i++;
                    j++;
                    dir = direction::right;
                    break;
            }
        }
        res.resize(row * coloum);
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

void printMatrix(vector<vector<int>> &mat) {
    for (auto &a : mat) {
        for (auto &b : a)
            std::cout << b << " ";
        std::cout << std::endl;
    }
}

int main() {
//    vector<vector<int>> matrix{
//            {1,2,3},
//            {4,5,6},
//            {7,8,9}
//    };
    //vector<vector<int>> matrix{
    //	{ 1,2,3,4 },
    //	{ 5,6,7,8 },
    //	{ 9,10,11,12},
    //	{13,14,15,16}
    //};
    vector<vector<int>> matrix{
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}};
    std::cout << "before spiral: \n";
    printMatrix(matrix);

    auto res = Solution().spiralOrder(matrix);
    std::cout << "after spiral order : \n ";
    for (auto &a: res) {
        std::cout << a << " ";
    }

}