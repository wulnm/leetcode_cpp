/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution
{
public:
    int myAtoi(string s)
    {
        if (s.length() == 0)
            return 0;
        int res = 0;
        int signal = 1;
        int pos = -1;
        while (++pos < s.length() && s.at(pos) == ' ')
            ;
        if (pos == s.length())
            return 0;
        if (s.at(pos) == '-')
        {
            signal = -1;
            pos++;
        }
        else if (s.at(pos) == '+')
            pos++;
        if (pos == s.length())
            return 0;
        char c = s.at(pos);
        while (pos < s.length() && c >= '0' && c <= '9')
        {
            int num = c - '0';
            if (signal == 1 && ((res > 214748364) || (res == 214748364 && num > 7)))
                return 2147483647;
            if (signal == -1 && ((res > 214748364) || (res == 214748364 && num > 8)))
                return -2147483648;
            if (signal == -1 && (res == 214748364 && num == 8))
            {
                return -2147483648;
            }
            res = res * 10 + num;
            pos++;
            if (pos == s.length())
                break;
            c = s.at(pos);
        }

        return res * signal;
    }
};
// @lc code=end
