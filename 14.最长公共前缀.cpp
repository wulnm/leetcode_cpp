/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res;
        if (strs.empty())
        {
            res = "";
            return res;
        }

        int cnt = 0;
        char cres[2050];
        char cur = '0';
        while (1)
        {
            if (strs.at(0).length() == 0)
            {
                res = "";
                return res;
            }
            bool flag = false;
            cur = strs.at(0).at(cnt);
            if (strs.at(0).length() - 1 <= cnt)
                flag = true;
            for (int i = 1; i < strs.size(); i++)
            {
                if (strs.at(i).length() == 0)
                {
                    res = "";
                    return res;
                }
                // 最短串即将结束
                if (strs.at(i).length() - 1 == cnt)
                    flag = true;
                // 前缀不一致
                if (strs.at(i).at(cnt) != cur)
                {
                    cres[cnt] = '\0';
                    res = cres;
                    return res;
                }
            }
            cres[cnt++] = cur;
            if (flag)
            {
                cres[cnt] = '\0';
                res = cres;
                return res;
            }
        }
    }
};
// @lc code=end
