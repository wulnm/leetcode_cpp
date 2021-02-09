/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int min(int a, int b)
    {
        return a > b ? b : a;
    }
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int max = 0;
        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            int left = height.at(l);
            int right = height.at(r);
            int val = (r - l) * min(left, right);
            if (right > left)
            {
                l++;
            }
            else
            {
                r--;
            }
            max = max >= val ? max : val;
        }
        return max;
    }
};
// @lc code=end
