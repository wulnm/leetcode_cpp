/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
public:
    int total;
    char cres[50];
    string sres;
    vector<string> res;

    // int left; // 左括号数量

    void dfs(int index,int left)
    {
        if (index >= total){
            cres[index] = '\0';
            sres = cres;
            res.push_back(sres);
            return;
        }
        if (total - index > left)
        {
            cres[index] = '(';

            dfs(index + 1,left+1);
        }
        if (left > 0)
        {
            cres[index] = ')';

            dfs(index + 1,left-1);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        total = n*2;
        dfs(0,0);
        return res;
    }
};
// @lc code=end
