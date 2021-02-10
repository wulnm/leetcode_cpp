/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int l = 0, r = matrix[0].size() - 1, u = 0, d = matrix.size() - 1;
        while (l <= r && u <= d)
        {
            if (l == r && u == d)
            {
                res.push_back(matrix[u][l]);
                break;
            }

            for (int i = l; i < r; i++)
            {
                res.push_back(matrix[u][i]);
            }
            for (int i = u; i < d; i++)
            {
                res.push_back(matrix[i][r]);
            }

            for (int i = r; i > l; i--)
            {
                res.push_back(matrix[d][i]);
                if (u == d)
                    break;
            }

            for (int i = d; i > u; i--)
            {
                res.push_back(matrix[i][l]);
                if (l == r)
                    break;
            }
            l++;
            r--;
            u++;
            d--;
        }
        return res;
    }
};
// @lc code=end
