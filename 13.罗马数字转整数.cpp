/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char cur = s.at(i);
            char next;
            if (i + 1 < s.length())
                next = s.at(i + 1);
            else
                next = '.';
            if (cur == 'I')
            {
                if (next == 'V' || next == 'X')
                {
                    res += -1;
                }
                else
                {
                    res += 1;
                }
            }
            if (cur == 'X')
            {
                if (next == 'L' || next == 'C')
                {
                    res += -10;
                }
                else
                {
                    res += 10;
                }
            }
            if (cur == 'C')
            {
                if (next == 'D' || next == 'M')
                {

                    res += -100;
                }
                else
                {
                    res += 100;
                }
            }
            if (cur == 'V')
                res += 5;
            if (cur == 'L')
                res += 50;
            if (cur == 'D')
                res += 500;
            if (cur == 'M')
                res += 1000;
        }
        return res;
    }
};
// @lc code=end
