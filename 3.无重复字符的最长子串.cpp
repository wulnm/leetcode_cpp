/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cur=0,last = 0,max = 0;
        for (int i = 0; i < s.length(); i++)
        {
            cur =1 ;
            for (int j = 1; j <= last; j++)
            {
                char t= s.at(i-j);
                if(t == s.at(i))
                    break;
                cur++;
            }
            max = cur>max?cur:max;
            last = cur;
        }
        return max;
    }
};
// @lc code=end

