/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        int a = min(m,n)-1,b=m+n-2;
        long long y=1;
        for (int i = 0; i <a; i++)
        {
            y*=(b-i);
            y/=(i+1);
        }
        return y;
    }
};
// @lc code=end

