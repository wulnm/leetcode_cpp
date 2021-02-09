/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int cur = 0, next = 0, i = 0;
        while (next < nums.size())
        {
            while (i < nums.size() - 1 && nums[next] == nums[++i])
                ;
            
            if (i > next && nums[i] != nums[next])
            {
                nums[++cur] = nums[i];
                next = i;
            }
            else{
                break;
            }
        }
        return cur +1 ;
    }
};
// @lc code=end
