/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> line[9];
        unordered_set<char> col[9];
        unordered_set<char> mat[9];
        for (int i = 0; i < 9; i++)
        {

            for (int j = 0; j < 9; j++)
            {
                // cout<<board[i][j]<<" ";
                if (board[i][j] == '.' || board[i][j] == '\0')
                    continue;
                if (col[j].find(board[i][j]) == col[j].end())
                    col[j].insert(board[i][j]);
                else
                {
                    return false;
                }

                if (line[i].find(board[i][j]) == line[i].end())
                    line[i].insert(board[i][j]);
                else
                {
                    return false;
                }

                int pos = (i / 3)*3 + j / 3;
                if (mat[pos].find(board[i][j]) == mat[pos].end())
                    mat[pos].insert(board[i][j]);
                else
                {
                    return false;
                }
            }
            // cout<<'\n';
        }
        return true;
    }
};
// @lc code=end
