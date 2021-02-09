/*
* @lc app=leetcode.cn id=29 lang=cpp
*
* [29] 两数相除
*/

// @lc code=start
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int lv, rv, res = 0, cnt = 1;
        int signal = 1;
        if ((dividend < 0 && divisor > 0) || (divisor < 0 && dividend > 0))
        {
            signal = -1;
        }
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
            return (dividend == -2147483648) ? 2147483647 : -dividend;
        if (divisor == -2147483648)
            return dividend==-2147483648?1:0;
        if (dividend == divisor)
            return 1;
        if (dividend == -divisor)
            return -1;
        if (dividend == -2147483648)
        {
            res += 1;
            dividend += abs(divisor);
        }
        if (abs(dividend) < abs(divisor))
            return res*signal;
        
        
        

        // 指数爆炸法
        stack<int> rvs;
        stack<int> cnts;

        lv = abs(dividend);
        rv = abs(divisor);

        rvs.push(rv);
        cnts.push(cnt);
        while (rv < lv - rv)
        {
            rv += rv;
            cnt += cnt;
            rvs.push(rv);
            cnts.push(cnt);
        }
        res += cnts.top();
        while (!rvs.empty())
        {
            while (!rvs.empty() && rvs.top() > lv - rv)
            {
                rvs.pop();
                cnts.pop();
            }
            if (rvs.empty() || rvs.top() == lv - rv)
            {
                int temp = (cnts.empty()) ? 0 : cnts.top();
                return (res + temp) * signal;
            }
            int tmp = rvs.top();
            int c = cnts.top();
            while (tmp < lv - rv)
            {
                rv += tmp;
                res += c;
            }
        }

        return 0;
    }
};
// @lc code=end
