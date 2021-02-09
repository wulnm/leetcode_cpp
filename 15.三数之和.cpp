/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++)
        {
            if(i>0&&nums.at(i) == nums.at(i-1))
                continue;
            int left = i + 1, right = nums.size() - 1;
            int need = -1 * nums.at(i);
            while (left < right)
            {
                int sum = nums.at(left) + nums.at(right);
                if (sum == need)
                {
                    res.push_back({nums.at(i), nums.at(left), nums.at(right)});
                    // res.push_back({i, left, right});
                    left++;
                    right--;
                    while (left < right && nums.at(left) == nums.at(left - 1))
                        left++;
                    while (right > left && nums.at(right) == nums.at(right + 1))
                        right--;
                }
                else if (sum > need)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }

        return res;
    }
};
// @lc code=end
