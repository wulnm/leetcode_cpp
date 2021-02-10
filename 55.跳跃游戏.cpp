/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = 0;
        while (!nums.empty()&&cur + nums[cur] <nums.size()-1)
        {
            int next = cur + nums[cur];
            int max = cur;
            for (int i = cur; i <= next; i++)
            {
                if(i+nums[i]>max+nums[max]){
                    max = i;
                }
            }
            if(max == cur)
                return false;
            cur = max;
        }
        return true;
    }
};
// @lc code=end

