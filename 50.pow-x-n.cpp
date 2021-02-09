/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        stack<int> cnts;
        stack<double> nums;
        bool flag = false;
        if (x == -1)
        {
            return (n % 2) ? -1 : 1;
        }
        if (x == 1)
            return 1;

        double res = 1;
        int cnt = 1;
        int sum = 0; // 幂总数
        double num = x;
        if (n < 0)
        {
            if (n == -2147483648)
            {
                n = -2147483647;
                res = x;
            }

            flag = true;
            n = -n;
        }
        cnts.push(cnt);
        nums.push(num);
        while (cnt  < n-cnt)
        {
            cnt *= 2;
            num *= num;
            if (num == 0)
            {
                return 0;
            }
            if (num == 1)
            {
                return 1;
            }
            cnts.push(cnt);
            nums.push(num);
        }
        while (!cnts.empty() && sum < n)
        {
            int c = cnts.top();
            cnts.pop();
            double m = nums.top();
            nums.pop();
            while (sum  <= n-c)
            {
                sum += c;
                res *= m;
            }
        }
        return (flag) ? 1 / res : res;
    }
};
// @lc code=end
